%% task2.1
im1 = imread('../lec2/peppers.png');
grayim1 = rgb2gray(im1);
gausnoise_im1 = imnoise(grayim1, 'gaussian');
[m,n,d] = size(gausnoise_im1);
mymed_im1 = gausnoise_im1;
myavg_im1 = gausnoise_im1;
%median filter 3*3
for i=2:m-1
    for j = 2:n-1
        medianfilter = gausnoise_im1(i-1:i+1, j-1:j+1);
        mid = median(reshape(medianfilter,1,9));
        mymed_im1(i, j) = mid;
    end
end
med_im1 = medfilt2(gausnoise_im1);
%smoothing filter 3*3(average filter)
for i=2:m-1
    for j = 2:n-1
        avgfilter = gausnoise_im1(i-1:i+1, j-1:j+1);
        avg = mean(reshape(avgfilter,1,9));
        myavg_im1(i, j) = avg;
    end
end
H = fspecial('average');
avg_im1 = imfilter(gausnoise_im1, H);

%laplacian filter 3*3
H = fspecial('laplacian');
lap_im1 = imfilter(gausnoise_im1, H);

figure(1);
subplot(2,3,1);
imshow(gausnoise_im1);
title('noise');
subplot(2,3,4);
imshow(lap_im1);
title('laplacian');
subplot(2,3,2);
imshow(mymed_im1);
title('my median');
subplot(2,3,5);
imshow(med_im1);
title('median');
subplot(2,3,3);
imshow(myavg_im1);
title('my avg');
subplot(2,3,6);
imshow(avg_im1);
title('avg');

%% task2.2
H = fspecial('average');
avg2 = imfilter(gausnoise_im1, H);%3*3 averaging kernel
tic;
H = fspecial('average',[10,10]);
t0 = toc;
tic;
avg3 = imfilter(gausnoise_im1, H , 'conv');
t1 = toc;
H = fspecial('average',[20,20]);
tic;
avg4 = imfilter(gausnoise_im1, H , 'conv');
t2 = toc;
figure(2);
subplot(1,4,1);
imshow(gausnoise_im1);
subplot(1,4,2);
imshow(avg2);
subplot(1,4,3);
imshow(avg3);
subplot(1,4,4);
imshow(avg4);
figure(5);
plot([3, 10, 20], [t0, t1, t2]);
H = fspecial('gaussian', [3 3], 1);
tic;
gaus1 = imfilter(gausnoise_im1, H);
t1 = toc;
figure(6);
subplot(1,3,1);
imshow(gausnoise_im1);
subplot(1,3,2);
imshow(avg2);
subplot(1,3,3);
imshow(gaus1);
%% task2.3
H = fspecial('prewitt');
prew1 = imfilter(im1, H);
prew2 = imfilter(im1, H');
H = fspecial('sobel');
sobel1 = imfilter(im1, H);
sobel2 = imfilter(im1, H');
figure(3);
subplot(2,2,1);
imshow(prew1);
title('prew');
subplot(2,2,2);
imshow(prew2);
title('prew.T');
subplot(2,2,3);
imshow(sobel1);
title('sobel');
subplot(2,2,4);
imshow(sobel2);
title('sobel.T');

%% task2.4
gausnoise2 = imnoise(im1, 'gaussian');
gausnoise3 = im2double(im1);
for i =1:10
    gausnoise3 = gausnoise3 + im2double(imnoise(im1, 'gaussian', 0, 0.1));
end
gausnoise3 = gausnoise3./10;
gausnoise4 = im2double(im1);
for i =1:50
    gausnoise4 = gausnoise4 + im2double(imnoise(im1, 'gaussian', 0, 0.1));
end
gausnoise4 = gausnoise4./50;
gausnoise5 = im2double(im1);
for i =1:100
    gausnoise5 = gausnoise5 + im2double(imnoise(im1, 'gaussian', 0, 0.1));
end
gausnoise5 = gausnoise5./100;
gausnoise6 = im2double(im1);
for i =1:1000
    gausnoise6 = gausnoise6 + im2double(imnoise(im1, 'gaussian', 0, 0.1));
end
gausnoise6 = gausnoise6./1000;
figure(4);
subplot(1,4,1);
imshow(gausnoise3);
title('10');
subplot(1,4,2);
imshow(gausnoise4);
title('50');
subplot(1,4,3);
imshow(gausnoise5);
title('100');
subplot(1,4,4);
imshow(gausnoise6);
title('1000');








