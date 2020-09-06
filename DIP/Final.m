%% problem 1
im1 = im2double(imread('mamo1.jpg'));
im2 = imread('ultrasound2.jpg');
im3 = imread('building03.png');
im4 = imread('building02.png');
figure;
subplot(1,4,1);
imshow(im1);
title('im1');
subplot(1,4,2);
imshow(im2);
title('im2');
subplot(1,4,3);
imshow(im3);
title('im3');
subplot(1,4,4);
imshow(im4);
title('im4');
%% problem 2
t = rgb2ycbcr(im1);
yim1 = t(:,:,1);
t = rgb2ycbcr(im2);
yim2 = t(:,:,1);
t = rgb2ycbcr(im3);
yim3 = t(:,:,1);
t = rgb2ycbcr(im4);
yim4 = t(:,:,1);
%% problem 3
n1 = imnoise(yim1, 'gaussian');
n2 = imnoise(yim2, 'gaussian');
n3 = imnoise(yim3, 'gaussian');
n4 = imnoise(yim4, 'gaussian');
%% problem 4 dct noise estimate
dctn1 = dct2(n1);
dctn2 = dct2(n2);
dctn3 = dct2(n3);
dctn4 = dct2(n4);
sigma1 = dctn1(700:end, 1100:end).*dctn1(700:end, 1100:end);
sigma2 = dctn2(150:end, 200:end).*dctn2(150:end, 200:end);
sigma3 = dctn3(470:end, 540:end).*dctn3(470:end, 540:end);
sigma4 = dctn4(560:end, 400:end).*dctn4(560:end, 400:end);
beta = 4;
nv1 = beta * mean(mean(sigma1));
nv2 = beta * mean(mean(sigma2));
nv3 = 2 * mean(mean(sigma3));
nv4 = 2 * mean(mean(sigma4));

%% problem 5 dct wiener filter
sv1 = dctn1.*dctn1 + 0.001;
sv2 = dctn2.*dctn2 + 0.001;
sv3 = dctn3.*dctn3 + 0.001;
sv4 = dctn4.*dctn4 + 0.001;
wf1 = 1+(nv1./sv1);
wf2 = 1+(nv2./sv2);
wf3 = 1+(nv3./nv3);
wf4 = 1+(nv4./nv4);
wf1 = 1./wf1;
wf2 = 1./wf2;
wf3 = 1./wf3;
wf4 = 1./wf4;
filtered1 = dctn1.*wf1;
filtered2 = dctn2.*wf2;
filtered3 = dctn3.*wf3;
filtered4 = dctn4.*wf4;
filteredy1 = idct2(filtered1);
filteredy2 = idct2(filtered2);
filteredy3 = idct2(filtered3);
filteredy4 = idct2(filtered4);
filteredy1 = 255.*imadjust(filteredy1, [], [0 1]);
figure(1);
subplot(4,2,1);
imshow(n1);
title('noise1');
subplot(4,2,2);
imshow(uint8(filteredy1));
title('filtered 1');
subplot(4,2,3);
imshow(n2);
title('noise2');
subplot(4,2,4);
imshow(uint8(filteredy2));
title('filtered 2');
subplot(4,2,5);
imshow(n3);
title('noise3');
subplot(4,2,6);
imshow(uint8(filteredy3));
title('filtered 3');
subplot(4,2,7);
imshow(n4);
title('noise4');
subplot(4,2,8);
imshow(uint8(filteredy4));
title('filtered 4');
%% problem 6 edge
sobel1 = edge(n1, 'Sobel');
prewitt1 = edge(n1, 'Prewitt');
roberts1 = edge(n1, 'Roberts');
canny1 = edge(n1, 'Canny', [0.2 0.35]);
figure(2);
subplot(1,4,1);
imshow(sobel1);
title('sobel');
subplot(1,4,2);
imshow(prewitt1);
title('prewitt');
subplot(1,4,3);
imshow(roberts1);
title('roberts');
subplot(1,4,4);
imshow(canny1);
title('canny');
sobel2 = edge(n2, 'Sobel');
prewitt2 = edge(n2, 'Prewitt');
roberts2 = edge(n2, 'Roberts');
canny2 = edge(n2, 'Canny', [0.2 0.45]);
figure(3);
subplot(1,4,1);
imshow(sobel2);
title('sobel');
subplot(1,4,2);
imshow(prewitt2);
title('prewitt');
subplot(1,4,3);
imshow(roberts2);
title('roberts');
subplot(1,4,4);
imshow(canny2);
title('canny');
sobel3 = edge(n3, 'Sobel');
prewitt3 = edge(n3, 'Prewitt');
roberts3 = edge(n3, 'Roberts');
canny3 = edge(n3, 'Canny', [0.2 0.45]);
figure(4);
subplot(1,4,1);
imshow(sobel3);
title('sobel');
subplot(1,4,2);
imshow(prewitt3);
title('prewitt');
subplot(1,4,3);
imshow(roberts3);
title('roberts');
subplot(1,4,4);
imshow(canny3);
title('canny');
sobel4 = edge(n4, 'Sobel');
prewitt4 = edge(n4, 'Prewitt');
roberts4 = edge(n4, 'Roberts');
canny4 = edge(n4, 'Canny', [0.2 0.3]);
figure(5);
subplot(1,4,1);
imshow(sobel4);
title('sobel');
subplot(1,4,2);
imshow(prewitt4);
title('prewitt');
subplot(1,4,3);
imshow(roberts4);
title('roberts');
subplot(1,4,4);
imshow(canny4);
title('canny');
%%
temp = reshape(n4, 662*497, 1);
ctemp = kmeans(double(temp), 2);
rtemp = reshape(ctemp, 662, 497);
imshow(label2rgb(rtemp));
title('kmeans segment');

%% problem 7


%% problem 8


%% problem 9


%% problem 10
[H1, Theta1, Rho1] = hough(canny4);
figure, imshow(imadjust(mat2gray(H1)), 'XData', Theta1, 'YData', Rho1, 'InitialMagnification', 'fit');
xlabel('\theta'), ylabel('\rho');
axis on, axis normal, hold on;
P = houghpeaks(H1, 6);
x = Theta1(P(:,2));y = Rho1(P(:,1));
plot(x, y, 's', 'color', 'r');
lines = houghlines(canny4, Theta1, Rho1, P, 'FillGap', 20, 'Minlength', 25);
figure, imshow(canny4);
hold on;
for i =1:length(lines)
    xy = [lines(i).point1; lines(i).point2];
    plot(xy(:,1),xy(:,2),'LineWidth',2,'Color','green');
    plot(xy(1,1),xy(1,2),'x','LineWidth',2,'Color','yellow');
    plot(xy(2,1),xy(2,2),'x','LineWidth',2,'Color','red');
end
%% problem 11
im5 = imread('friend.png');
t = rgb2ycbcr(im5);
y5 = t(:,:,1);
cb5 = t(:,:,2);
cr5 = t(:,:,3);
y_prewitt = edge(y5, 'Prewitt');
y_sobel = edge(y5, 'Sobel');
y_canny = edge(y5, 'Canny', [0.075, 0.175]);
cb_prewitt = edge(cb5, 'Prewitt');
cb_sobel = edge(cb5, 'Sobel');
cb_canny = edge(cb5, 'Canny', [0.075, 0.175]);
cr_prewitt = edge(cr5, 'Prewitt');
cr_sobel = edge(cr5, 'Sobel');
cr_canny = edge(cr5, 'Canny', [0.075, 0.175]);
figure;
subplot(1,3,1);
imshow(y_prewitt);
title('y prewitt');
subplot(1,3,2);
imshow(y_sobel);
title('y sobel');
subplot(1,3,3);
imshow(y_canny);
title('y canny');
figure;
subplot(1,3,1);
imshow(cb_prewitt);
title('cb prewitt');
subplot(1,3,2);
imshow(cb_sobel);
title('cb sobel');
subplot(1,3,3);
imshow(cb_canny);
title('cb canny');
figure;
subplot(1,3,1);
imshow(cr_prewitt);
title('cr prewitt');
subplot(1,3,2);
imshow(cr_sobel);
title('cr sobel');
subplot(1,3,3);
imshow(cr_canny);
title('cr canny');



%% problem 12







