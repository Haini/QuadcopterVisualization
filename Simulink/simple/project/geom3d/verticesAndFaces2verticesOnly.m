function v_only = verticesAndFaces2verticesOnly( v, f )
%VERTICESANDFACES2VERTICESONLY Converts description of a mesh with vertices and faces to only vertices.
%   Faces index the vertices to describe the mesh. Face indices will be
%   replaced by points in matrix v.
% 

%% create matrix of vertices for merged v,f
num_f = size(f,1);          % num faces
num_v_per_f = size(f,2);	% num vertices in one face
v_only = zeros([num_f num_v_per_f*3]);

%% substitute indices with vertices
for i = 1:num_f
    for j = 1:num_v_per_f
        vertex = v(f(i,j),:);
        v_only(i,((j-1)*3+1):((j-1)*3+3)) = vertex;  % x y z
    end
end

end

