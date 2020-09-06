%% problem1
im1 = imread('../lec3/image1.jpg');
im2 = imread('../lec3/image2.jpg');

%% problem2
H = fspecial('gaussian', [5 5], 2);

%% problem3
ycbcrim1 = rgb2ycbcr(im1);
ycbcrim2 = rgb2ycbcr(im2);
y1 = ycbcrim1(:,:,1); %y channel of im1
y2 = ycbcrim2(:,:,1); %y channel of im2

%% problem4
f_y1 = imfilter(y1, H, 'conv'); %spatial conv on y1
f_y2 = imfilter(y2, H, 'conv'); %spatial conv on y2
f_yim1 = ycbcrim1;
f_yim1(:,:,1) = f_y1; %combine the y cbcr of im1
rgbfyim1 = ycbcr2rgb(f_yim1); %convert to rgb
f_yim2 = ycbcrim2;
f_yim2(:,:,1) = f_y2; %combine the y cbcr of im2
rgbfyim2 = ycbcr2rgb(f_yim2); %convert to rgb
figure(1);
subplot(2,2,1);
imshow(im1);
title('origin im1');
subplot(2,2,2);
imshow(rgbfyim1);
title('filtered im1');
subplot(2,2,3);
imshow(im2);
title('origin im2');
subplot(2,2,4);
imshow(rgbfyim2);
title('filtered im2');

%% problem5


%% problem6


%% problem7
fd_y = fft2(y1);
%ftH = zeros(400,400);
%ftH(1:5,1:5) = H;
ftH = fft2(H, 400, 400); %convert the kernel
filtered_fdy = fd_y.*ftH; %do the frequency filter
ifdy = ifft2(filtered_fdy); %inverse fft
f_fdy1 = ycbcrim1;
f_fdy1(:,:,1) = ifdy; %combine the filtered y component
rgbffdy1 = ycbcr2rgb(uint8(f_fdy1)); %get the result
figure(2);
subplot(1,2,1);
imshow(rgbfyim1);
title('spatial domain');
subplot(1,2,2);
imshow(rgbffdy1);
title('frequency domain');

%% problem8
dctim1 = dct2(rgb2gray(im1)); %DCT of im1
dctim2 = dct2(rgb2gray(im2)); %DCT of im2
fdcti1 = zeros(400*1.75,400*1.75); 
fdcti2 = zeros(300*0.6, 400*0.6);
fdcti1(1:400,1:400) = dctim1; %pad with zeros 
fdcti2 = dctim2(1:300*0.6, 1:400*0.6); %truncate the sequence
itim1 = idct2(fdcti1); %inverse DCT of im1
itim2 = idct2(fdcti2); %inverse DCT of im2
cr1 = sqrt((400*400)/(400*1.75*400*1.75)); % cr of im1
cr2 = sqrt((400*300)/(400*0.6*300*0.6)); %cr of im2
out1 = uint8(cr1*itim1); %normalization
out2 = uint8(cr2*itim2);
figure, imshow(rgb2gray(im1));
figure, imshow(out1);
figure, imshow(rgb2gray(im2));
figure, imshow(out2);









