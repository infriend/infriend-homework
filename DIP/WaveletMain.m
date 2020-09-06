% wavelet_main
close all;
clear all;
clc;

X =  imread('lena.png'); 
X = X(:,:,2);

[c,s]=wavedec2(X,4,'haar');
[H1,V1,D1] = detcoef2('all',c,s,1);
A1 = appcoef2(c,s,'haar',1); 
V1img = wcodemat(V1,255,'mat',1);
H1img = wcodemat(H1,255,'mat',1);
D1img = wcodemat(D1,255,'mat',1);
A1img = wcodemat(A1,255,'mat',1);

[H2,V2,D2] = detcoef2('all',c,s,2);
A2 = appcoef2(c,s,'haar',2); 
V2img = wcodemat(V2,255,'mat',1);
H2img = wcodemat(H2,255,'mat',1);
D2img = wcodemat(D2,255,'mat',1);
A2img = wcodemat(A2,255,'mat',1);

[H3,V3,D3] = detcoef2('all',c,s,3);
A3 = appcoef2(c,s,'haar',3); 
V3img = wcodemat(V3,255,'mat',1);
H3img = wcodemat(H3,255,'mat',1);
D3img = wcodemat(D3,255,'mat',1);
A3img = wcodemat(A3,255,'mat',1);

[H4,V4,D4] = detcoef2('all',c,s,4);
A4 = appcoef2(c,s,'haar',4); 
V4img = wcodemat(V4,255,'mat',1);
H4img = wcodemat(H4,255,'mat',1);
D4img = wcodemat(D4,255,'mat',1);
A4img = wcodemat(A4,255,'mat',1);


subplot(2,2,1);
imagesc(A1img);
colormap pink(255);
title('Approximation Coef. of Level 1');

subplot(2,2,2);
imagesc(H1img);
title('Horizontal detail Coef. of Level 1');

subplot(2,2,3);
imagesc(V1img);
title('Vertical detail Coef. of Level 1');

subplot(2,2,4);
imagesc(D1img);
title('Diagonal detail Coef. of Level 1');


%***********************************

figure;
subplot(2,2,1);
imagesc(A2img);
colormap pink(255);
title('Approximation Coef. of Level 2');

subplot(2,2,2)
imagesc(H2img);
title('Horizontal detail Coef. of Level 2');

subplot(2,2,3)
imagesc(V2img);
title('Vertical detail Coef. of Level 2');

subplot(2,2,4)
imagesc(D2img);
title('Diagonal detail Coef. of Level 2');

%***********************************
figure;
subplot(2,2,1);
imagesc(A3img);
colormap pink(255);
title('Approximation Coef. of Level 3');

subplot(2,2,2)
imagesc(H3img);
title('Horizontal detail Coef. of Level 3');

subplot(2,2,3)
imagesc(V3img);
title('Vertical detail Coef. of Level 3');

subplot(2,2,4)
imagesc(D3img);
title('Diagonal detail Coef. of Level 3');

figure;
subplot(2,2,1);
imagesc(A4img);
colormap pink(255);
title('Approximation Coef. of Level 4');

subplot(2,2,2)
imagesc(H4img);
title('Horizontal detail Coef. of Level 4');

subplot(2,2,3)
imagesc(V4img);
title('Vertical detail Coef. of Level 4');

subplot(2,2,4)
imagesc(D4img);
title('Diagonal detail Coef. of Level 4');
%%
am1 = sqrt(V1img.^2+H1img.^2);
am2 = sqrt(V2img.^2+H2img.^2);
am3 = sqrt(V3img.^2+H3img.^2);
am4 = sqrt(V4img.^2+H4img.^2);
figure;
subplot(2,2,1);
imagesc(am1);
title('level1');
subplot(2,2,2);
imagesc(am2);
title('level2');
subplot(2,2,3);
imagesc(am3);
title('level3');
subplot(2,2,4);
imagesc(am4);
title('level4');

%%
[ca, ch, cv, cd] = dwt2(X, 'db4');
result = idwt2(ca*0, ch, cv, cd, 'db4')/256;
imshow(imadjust(result, [0 1], [1 0]));


