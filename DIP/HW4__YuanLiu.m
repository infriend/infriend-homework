%% problem1
letter = ["a", "e", "g", "k","l","z"];
freq = [3,8,13,19,23,34];
temp = [];
res = ["","","","","",""];
while length(letter)>=2
    [freq, index] = sort(freq);
    letter = letter(index);
    temp = char(letter(1));
    for i = 1:length(temp)
        if temp(i) == 'a'
            res(1) = strcat("0",res(1));
        end
        if temp(i) == 'e'
            res(2) = strcat("0",res(2));
        end
        if temp(i) == 'g'
            res(3) = strcat("0",res(3));
        end
        if temp(i) == 'k'
            res(4) = strcat("0",res(4));
        end
        if temp(i) == 'l'
            res(5) = strcat("0",res(5));
        end
        if temp(i) == 'z'
            res(6) = strcat("0",res(6));
        end
    end
    temp = char(letter(2));
    for i = 1:length(temp)
        if temp(i) == 'a'
            res(1) = strcat("1",res(1));
        end
        if temp(i) == 'e'
            res(2) = strcat("1",res(2));
        end
        if temp(i) == 'g'
            res(3) = strcat("1",res(3));
        end
        if temp(i) == 'k'
            res(4) = strcat("1",res(4));
        end
        if temp(i) == 'l'
            res(5) = strcat("1",res(5));
        end
        if temp(i) == 'z'
            res(6) = strcat("1",res(6));
        end
    end
    letter(1) = strcat(letter(1),letter(2));
    letter(2) = [];
    freq(1) = freq(1)+ freq(2);
    freq(2) = [];
end

%% problem3
%im1 = double(imread('mamo1.jpg'));
im1 = imread('mamo1.jpg');
im2 = imread('ultrasound2.jpg');

%% problem4
yim1 = rgb2ycbcr(im1);
yim2 = rgb2ycbcr(im2);
y1 = yim1(:,:,1);
y2 = yim2(:,:,1);

%% problem5
noise1 = imnoise(y1, 'gaussian');
noise2 = imnoise(y2, 'gaussian');

%% problem6
dctn1 = dct2(noise1);
dctn2 = dct2(noise2);
sigma1 = dctn1(700:end, 1100:end).*dctn1(700:end, 1100:end);
sigma2 = dctn2(100:end, 150:end).*dctn2(100:end, 150:end);
nv1 = 4*mean(mean(sigma1));
nv2 = 4*mean(mean(sigma2));
%% problem7
sv1 = dctn1.*dctn1 + 0.001;
sv2 = dctn2.*dctn2 + 0.001;
wf1 = 1+(nv1./sv1);
wf2 = 1+(nv2./sv2);
wf1 = 1./wf1;
wf2 = 1./wf2;
filtered1 = dctn1.*wf1;
filtered2 = dctn2.*wf2;
f1 = uint8(idct2(filtered1));
f2 = uint8(idct2(filtered2));
figure(2);
subplot(2,2,1);
imshow(f1);
title('f1');
subplot(2,2,2);
imshow(f2);
title('f2');
subplot(2,2,3);
imshow(noise1);
title('noise1');
subplot(2,2,4);
imshow(noise2);
title('noise2');
%% problem8
wn1 = wiener2(noise1);
wn2 = wiener2(noise2);
nlm1 = simple_nlm(im2double(noise1), 3,2,1,10,0);
nlm2 = simple_nlm(im2double(noise2), 3,2,1,10,0);
figure(3)
subplot(2,2,1);
imshow(wn1);
title('wn1');
subplot(2,2,2);
imshow(wn2);
title('wn2');
subplot(2,2,3);
imshow(nlm1);
title('nlm1');
subplot(2,2,4);
imshow(nlm2);
title('nlm2');


%% problem9
lena = imread('Lena.png');
[c,s] = wavedec2(lena(:,:,2), log2(512)-1, 'haar');
out = ones(512,512);
[w, h] = size(out);
for i = 1:8
    [H1,V1,D1] = detcoef2('all',c,s,i);
    A1 = appcoef2(c,s,'haar',i); 
    V1img = wcodemat(V1,255,'mat',1);
    H1img = wcodemat(H1,255,'mat',1);
    D1img = wcodemat(D1,255,'mat',1);
    A1img = wcodemat(A1,255,'mat',1);
    out(1:0.5*w, 0.5*h+1:h) = H1img;
    out(0.5*w+1:w, 1:0.5*h) = V1img;
    out(0.5*w+1:w, 0.5*h+1:h) = D1img;
    h = 0.5*h;
    w = 0.5*w;
end
imshow(uint8(out));
