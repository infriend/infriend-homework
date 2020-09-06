%% exp1
%reading the RGB image
im = imread('../lec1/crab.jpg');
%imshow(im);
s = size(im);
%convert to gray image
im_gray = rgb2gray(im);
s_gray = size(im_gray);
%convert to binary image
im_bw = im2bw(im);
T = graythresh(im);
level = 0.7;
im_bw = im2bw(im, level);
s_bw = size(im_bw);
figure(3);
subplot(1,3,1); imshow(im);
subplot(1,3,2); imshow(im_gray);
subplot(1,3,3); imshow(im_bw);
row8 = im(8,:);
row8;
plot(row8);title('Row8'); axis tight;
%% exp2
J = imadjust(im, [0,1], [1,0]);
imshow(J);
%% exp3
J = histeq(im);
subplot(1,2,1);imshow(im);
subplot(1,2,2); imshow(J);
J = histeq(im);
subplot(1,2,1);imhist(im);title('Original')
subplot(1,2,2); imhist(J);title('Processed');


%% task1
image = imread('../pout.tif'); %read gray scale image
figure(1);
subplot(1,2,1);
imshow(image);%display the image with scale
newimg = imadjust(image, [50/255,150/255],[0,1]);
subplot(1,2,2);
imshow(newimg);%display pixels having intensity values<50 to 0, >150 to 255

%% task2
image = imread('../pout.tif');
figure(2);
subplot(1,3,1);
imshow(image);
subplot(1,3,2);
imshow(fliplr(image));
subplot(1,3,3);
imshow(flipud(image));
