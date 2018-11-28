function [nodes] = pathPlanner(start,waypoints,obstacles, obstacles_AABB, quadrotor_AABB, worldMin, worldMax, numParticles)

rng(42);
waypoints = vertcat(start,waypoints);
len = length(waypoints)-1;
parfor n = 1:len
    newNodes = segmentPlanner(waypoints(n,:), waypoints(n+1,:), obstacles, obstacles_AABB, quadrotor_AABB, worldMin, worldMax, numParticles);
    
    %% 2-opt
    target = waypoints(n+1,:);
    edit=1;
    while edit == 1
        edit=0;
        steps = size(newNodes,1)-1;
        for m = 1:steps
            p1=newNodes(m,:);
            if m ~= steps
                p2=newNodes(m+2,:);
            else
                p2=target;
            end
            free = checkFreeP(obstacles,obstacles_AABB,p1,p2);
            if free
               newNodes(m+1,:)=[]; 
               edit=1;
               break
            end
        end
    end

    
    nodearr(n).data=newNodes;
end
nodes=[];
for n=1:length(nodearr)
    nodes=vertcat(nodes,nodearr(n).data);
end
nodes=vertcat(nodes,waypoints(len+1,:));
%add one node after the goal
nodes = vertcat(nodes, waypoints(len+1,:)+[0,1,0]);

function [nodes] = segmentPlanner(start, target, obstacles, obstacles_AABB, quadrotor_AABB, worldMin, worldMax, numParticles)

deltaD = 2;
worldSize=worldMax-worldMin;

qnew.pos=start;
qnew.parent=0;
qnew.cost=0;
T(1)=qnew;

for i=1:numParticles
    qrand = sampleFree(obstacles, obstacles_AABB,quadrotor_AABB, worldSize, worldMin,start,target);
    dist = [];
    for n = 1:length(T)
         d = norm(T(n).pos-qrand.pos);
         dist = [dist d];
     end
     [val, idx] = min(dist);
     qnear = T(idx);
     
     qnew = moveTo(qnear,qrand,deltaD);
     free = checkFree(obstacles,obstacles_AABB, qnear,qnew);
     if free == 1
        Qnear =  getNeighborhood(T,qnew,1);
        qparent = bestParent(obstacles,obstacles_AABB,Qnear,idx,qnear,qnew);
        idxParent = idxOfNode(T,qparent);
        qnew.cost = qparent.cost + norm(qnew.pos-qparent.pos);
        qnew.parent=idxParent;
        T = [T qnew];
       % plot2Parent(T,qnew);
        T=reWire(obstacles,obstacles_AABB, T, Qnear, qparent, qnew);
     else
         i = i - 1;
     end
end
% for n = 1:length(T)
%    if T(n).parent ~= 0
%       plot2Parent(T,T(n));
%    end
% end


cmin=10000;
idxEnd=0;
for n = 1:length(T)
    d=norm(T(n).pos-target);
    c = T(n).cost + d;
    if (d<2) && (c<cmin)
        idxEnd=n;
        cmin=c;
    end
end
nodes = [];


p1 = target;
p2 = T(idxEnd).pos;
v = [p1;p2];
%plot3(v(:,1),v(:,2),v(:,3),'LineWidth',6);hold on;
q=T(idxEnd);
nodes = vertcat(nodes, q.pos);
while q.parent ~= 0
    p1 = q.pos;
    p2 = T(q.parent).pos;
    v = [p1;p2];
    %plot3(v(:,1),v(:,2),v(:,3),'LineWidth',6);hold on;
    q=T(q.parent);
    nodes = vertcat(nodes, q.pos);
end
nodes=flipud(nodes);


function [idx] = idxOfNode(T,q)
    for n = 1:length(T)
        if T(n).pos == q.pos
            idx=n;
            break;
        end
    end

function plot2Parent(T,q)
    p1 = q.pos;
    p2 = T(q.parent).pos;
    v = [p1;p2];
    plot3(v(:,1),v(:,2),v(:,3));hold on;


function [d] = dist(p1,p2)
d = norm(p1-p2);

function [q] = sampleFree(obstacles, obstacles_AABB,quadrotor_AABB, worldSize, worldOffset,source,target)
    done=0;
    while done==0
        if(100*rand())<5
            %bias towards the target
            prand = rand(1,3).*4 - 2 + target;
        else
            %bias towards source 1/r²
            prand = ((rand(1,3).*2 -1).*rand(1,3)).*20 + source;
            if (prand(1) < worldOffset(1)) || (prand(2) < worldOffset(2)) || (prand(3) < worldOffset(3))
                continue;
            end
            max = worldOffset+worldSize;
            if (prand(1) > max(1)) || (prand(2) > max(2)) || (prand(3) > max(3))
                continue;
            end
        end
        colDet = myHasCrashedObstacle(obstacles,obstacles_AABB,quadrotor_AABB,prand,[0,0,0]);
        if ~any(colDet)
            done = 1;
            q.pos=prand;
        end
    end
function [qnew] = moveTo(q1,q2,deltaD)
    d = norm(q1.pos-q2.pos);
    if d > deltaD
       diff = q2.pos - q1.pos;
       qnew.pos = q1.pos + (diff/d)*deltaD;
       
    else
        qnew.pos=q2.pos;
    end
    
function [Qnear] = getNeighborhood(T, q, range)
    Qnear = [];
    for n = 1:length(T)
        d = norm(T(n).pos-q.pos);
        if d<range
           Qnear = [Qnear T(n)]; 
        end
    end

function [free] = checkFree(obstacles,obstacles_AABB, q1,q2)
    p1=q1.pos;
    p2=q2.pos;
    free = checkFreeP(obstacles,obstacles_AABB, p1,p2);
function [free] = checkFreeP(obstacles,obstacles_AABB, p1,p2)
    r = 0.8;
    diff=p2-p1;
    %4 start points, 4 end points
    obj.vertices=vertcat((0+[r,0,0]),(0+[0,r,0]),(0-[r,0,0]),(0-[0,r,0]),...
        (diff+[r,0,0]),(diff+[0,r,0]),(diff-[r,0,0]),(diff-[0,r,0]));
    obj.faces=[1 2 6; 1 5 6;1 4 5;4 5 8;3 4 8;3 7 8;2 3 6;3 6 7];
    colObjs = myHasCrashedObstacle(obstacles,obstacles_AABB,obj,p1,[0,0,0]);
    free = ~any(colObjs);
    
    
function [T] = reWire(obstacles,obstacles_AABB, T, Qnear, qparent, qnew)
    idxNew = idxOfNode(T,qnew);
    for n = 1:length(T)
        if T(n).pos == qparent.pos
            continue
        end
        if T(n).pos == qnew.pos
            continue
        end 
        
        d = norm(T(n).pos-qnew.pos);
        if d<5 && (qnew.cost + d) < T(n).cost
           free = checkFree(obstacles,obstacles_AABB,T(n),qnew);
           if free==1
              %rewire
              T(n).parent = idxNew;
              T(n).cost = qnew.cost + d;
           end
        end
    end


function [qparent] = bestParent(obstacles,obstacles_AABB,Qnear,idxMin,qmin,qnew)
qparent=qmin;
cmin=qmin.cost + norm(qnew.pos-qmin.pos);
for n = 1:length(Qnear)
    qtemp = moveTo(Qnear(n),qnew,1);
    free = checkFree(obstacles,obstacles_AABB,Qnear(n),qtemp);
    if free==1
        cost = Qnear(n).cost + norm(Qnear(n).pos-qtemp.pos);
        if cost < cmin
           qparent = Qnear(n);
           cmin = cost;
        end
    end
end



