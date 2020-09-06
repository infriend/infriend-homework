%% problem1 imread
im1 = imread('../lec2/mamo1.jpg');
im2 = imread('../lec2/ultrasound2.jpg');
im3 = imread('../lec2/ultrasound1.jpeg');
im4 = imread('../lec2/mamo2.jpg');
figure(1);
subplot(2,2,1);
imshow(im1);
subplot(2,2,2);
imshow(im2);
subplot(2,2,3);
imshow(im3);
subplot(2,2,4);
imshow(im4);

%% problem2 size
s1 = size(im1);
s2 = size(im2);
s3 = size(im3);
s4 = size(im4);

%% problem3 rgb2
im01 = im2double(im1);
lab_im1 = rgb2lab(im1);
rlab_im1 = lab2rgb(lab_im1);
xyz_im1 = rgb2xyz(im1);
rxyz_im1 = xyz2rgb(xyz_im1);
ycbcr_im1 = rgb2ycbcr(im1);
rycbcr_im1 = ycbcr2rgb(ycbcr_im1);
figure(2);
subplot(2,3,1);
imshow(lab_im1);
subplot(2,3,4);
imshow(rlab_im1);
subplot(2,3,2);
imshow(xyz_im1);
subplot(2,3,5);
imshow(rxyz_im1);
subplot(2,3,3);
imshow(ycbcr_im1);
subplot(2,3,6);
imshow(rycbcr_im1);

%% problem4 fspecial
B = fspecial('average');
temp = xyz_im1;
temp(:,:,1) = imfilter(xyz_im1(:,:,1), B);
avgim1 = xyz2rgb(temp);
B = fspecial('disk');
temp = xyz_im1;
temp(:,:,1) = imfilter(xyz_im1(:,:,1), B);
diskim1 = xyz2rgb(temp);
B = fspecial('gaussian');
temp = xyz_im1;
temp(:,:,1) = imfilter(xyz_im1(:,:,1), B);
gaussianim1 = xyz2rgb(temp);
B = fspecial('laplacian');
temp = xyz_im1;
temp(:,:,1) = imfilter(xyz_im1(:,:,1), B);
lapim1 = xyz2rgb(temp);
B = fspecial('log');
temp = xyz_im1;
temp(:,:,1) = imfilter(xyz_im1(:,:,1), B);
logim1 = xyz2rgb(temp);
B = fspecial('motion');
temp = xyz_im1;
temp(:,:,1) = imfilter(xyz_im1(:,:,1), B);
motionim1 = xyz2rgb(temp);
B = fspecial('prewitt');
temp = xyz_im1;
temp(:,:,1) = imfilter(xyz_im1(:,:,1), B);
preim1 = xyz2rgb(temp);
B = fspecial('sobel');
temp = xyz_im1;
temp(:,:,1) = imfilter(xyz_im1(:,:,1), B);
sobelim1 = xyz2rgb(temp);
B = fspecial('unsharp');
temp = xyz_im1;
temp(:,:,1) = imfilter(xyz_im1(:,:,1), B);
unsharpim1 = xyz2rgb(temp);
figure(2);
subplot(2,5,1);
imshow(im1);
title("raw");
subplot(2,5,2);
imshow(avgim1);
title("average");
subplot(2,5,3);
imshow(diskim1);
title("disk");
subplot(2,5,4);
imshow(gaussianim1);
title("gaussian");
subplot(2,5,5);
imshow(lapim1);
title("laplacian");
subplot(2,5,6);
imshow(logim1);
title("log");
subplot(2,5,7);
imshow(motionim1);
title("motion");
subplot(2,5,8);
imshow(preim1);
title("prewitt");
subplot(2,5,9);
imshow(sobelim1);
title("sobel");
subplot(2,5,10);
imshow(unsharpim1);
title("unsharp");
%% problem5 imnoise
gausnoise_im3 = imnoise(im3, 'gaussian');
spnoise_im3 = imnoise(im3, 'salt & pepper');
figure(3);
subplot(1,3,1);
imshow(im3);
subplot(1,3,2);
imshow(gausnoise_im3);
subplot(1,3,3);
imshow(spnoise_im3);

%% problem6 filter remove noise
H = fspecial('average');
avgfilter_gausim3 = imfilter(gausnoise_im3, H);
medfilter_spim3 = medfilt2(spnoise_im3);
figure(4);
subplot(2,2,1);
imshow(gausnoise_im3);
title('gausnoise');
subplot(2,2,3);
imshow(avgfilter_gausim3);
title('avg filter');
subplot(2,2,2);
imshow(spnoise_im3);
title('sp noise');
subplot(2,2,4);
imshow(medfilter_spim3);
title('med filter');

%% problem7 nlm
nlmfilter_im3 = simple_nlm(im2double(gausnoise_im3),3,2,1,5,0);
figure(5);
subplot(2,2,1);
imshow(im3);
title("origin");
subplot(2,2,2);
imshow(gausnoise_im3);
title("noise");
subplot(2,2,3);
imshow(avgfilter_gausim3);
title("avgfilter");
subplot(2,2,4);
imshow(nlmfilter_im3);
title("nlmfilter");

%% problem8 gray-world scale-by-max
blue = imread('../lec2/blue_image.jpg');
red = imread('../lec2/red_image.jpg');

balanced1 = grayworld(red);
balanced2 = ScaleByMax(blue);
figure(6);
subplot(2,2,1);
imshow(red);
title('red');
subplot(2,2,2);
imshow(blue);
title('blue');
subplot(2,2,3);
imshow(balanced1);
title('grayworld red');
subplot(2,2,4);
imshow(balanced2);
title('SbM blue');

function y = grayworld(image)
r = image(:,:,1);
g = image(:,:,2);
b = image(:,:,3);
avgrgb = [mean(mean(r)), mean(mean(g)), mean(mean(b))];
grayvalue = sum(avgrgb)/3;
scalevalue = grayvalue./avgrgb;
newI(:,:,1) = scalevalue(1)*r;
newI(:,:,2) = scalevalue(2)*g;
newI(:,:,3) = scalevalue(3)*b;
y = newI;
end

function y=ScaleByMax(img)
r = img(:,:,1);
g = img(:,:,2);
b = img(:,:,3);
Rmax=max(max(r));
Gmax=max(max(g));
Bmax=max(max(b));

Cmax=min([Rmax,Gmax,Bmax]);

% calculate the pix,which larger than Cmax
Nr=sum(r(:)>=Cmax);
Ng=sum(g(:)>=Cmax);
Nb=sum(b(:)>=Cmax);

% find the largest N for Nr Ng Nb
Nmax=max([Nr,Ng,Nb]);

for pix=Rmax:-1:0  % R
    if Nmax == Nr
        Rth = Cmax;
        break;
    end
    Lr=r>=pix; 
    nr=sum(Lr(:));
    if nr>=Nmax
        Rth=pix;
        break
    end
end

for pix=Gmax:-1:0   % G
    if Nmax == Ng
        Gth = Cmax;
        break;
    end
    Lr=g>=pix;
    nr=sum(Lr(:));
    if nr>=Nmax
        Gth=pix;
        break
    end
end

for pix=Bmax:-1:0 % B
    if Nmax == Nb
        Bth = Cmax;
        break;
    end
    Lr=b>=pix;
    nr=sum(Lr(:));
    if nr>=Nmax
        Bth=pix;
        break
    end
end
result(:,:,1) = double(Cmax)/double(Rth)*r;
result(:,:,2) = double(Cmax)/double(Gth)*g;
result(:,:,3) = double(Cmax)/double(Bth)*b;
y = result;
end








