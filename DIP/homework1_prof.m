%% problem1 imread two ultrasound images and two mammogram images
im1 = imread('../lec1/ultrasound1.jpeg');
im2 = imread('../lec1/ultrasound2.jpg');
im3 = imread('../lec1/mamo1.jpg');
im4 = imread('../lec1/mamo2.jpg');
figure(1);
subplot(2,2,1);
imshow(im1);
subplot(2,2,2);
imshow(im2);
subplot(2,2,3);
imshow(im3);
subplot(2,2,4);
imshow(im4);

%% problem2 size function
s1 = size(im1);
s2 = size(im2);
s3 = size(im3);
s4 = size(im4);

%% problem3 imadjust
newim1 = imadjust(im1,[0,1],[0,1],0.45);
newim2 = imadjust(im1,[0,1],[0,1],2.2);
figure(2);
subplot(1,2,1);
imshow(newim1);
subplot(1,2,2);
imshow(newim2);

%% problem4 imcomplement
reverse1 = imcomplement(im1);
reverse2 = imadjust(im1, [0,1],[1,0]);
figure(3);
subplot(1,3,1);
imshow(im1);
subplot(1,3,2);
imshow(reverse1);
subplot(1,3,3);
imshow(reverse2);

%% problem5 mat2gray
grayim4 = mat2gray(im4);
figure(4);
subplot(1,2,1);
imshow(im4);
subplot(1,2,2);
imshow(grayim4);

%% problem6 im2uint8
uintgray = im2uint8(grayim4);
figure(5);
subplot(1,2,1);
imshow(grayim4);
subplot(1,2,2);
imshow(uintgray);

%% problem7 logarithmic
g = log(1+double(im4));
gs = im2uint8(mat2gray(g));
figure(6);
imshow(gs);
%% problem8 imresize
reim4 = imresize(im4,[300,200]);
figure(7);
subplot(1,2,1);
imshow(im4);
subplot(1,2,2);
imshow(reim4);


