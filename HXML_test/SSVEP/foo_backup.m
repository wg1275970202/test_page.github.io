function B = foo(Icam)

%% Reformat the image data
N = 750;
Icam = uint8(reshape(Icam,[3,N,N]));
Icam = permute(Icam,[3,2,1]);

%% Convert to gray image
tmp = rgb2gray(Icam(:,:,1:3)); % codegen ok
tmp = uint8(imbinarize(tmp))*uint8(255);
tmp=cat(3,repmat(tmp,[1 1 3]),zeros(N,N,1,'uint8'));
tmp = permute(tmp,[3,2,1]);
B=tmp(:);


% Icam=[reshape(Icam,[3,N*N]); zeros(1,N*N,"uint8")];
% B=Icam(:);



end