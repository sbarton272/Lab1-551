%% 18-551 HW1
% Spencer Barton, David Lu

clear all
close all

%% Load

N = 2^10;

[y, Fs] = audioread('hw1_noisy.wav');

sound(y,Fs);
pause;


figure;
t = linspace(0,length(y)/Fs,length(y));
subplot(2,1,1); plot(t(1:100),y(1:100));
Y = fft(y,N);
w = ((0:(length(Y)-1)) - length(Y)/2) / length(Y) * 2;
subplot(2,1,2); plot(w, fftshift(abs(Y)));
title('Raw');

%%  Filter

bpf = fir1(64, [.45, .46]);

figure; title('Filter'); freqz(bpf);

fltY = filter(bpf,1,y);

sound(fltY,Fs);
pause;

figure;
t = linspace(0,length(fltY)/Fs,length(fltY));
subplot(2,1,1); plot(t(1:100),fltY(1:100));
fltFreqY = fft(fltY,N);
len = length(fltFreqY);
w = ((0:(len-1)) - len/2) / len * 2;
subplot(2,1,2); plot(w, fftshift(abs(fltFreqY)));
title('Filt');

%% Amplitude modulation

Ftarget = .455 * Fs / 2;
Fc = .5 * Fs / 2;

carrier = cos(2*pi*t*Fc);
modY = carrier.*fltY';

sound(modY,Fs);

figure;
t = linspace(0,length(modY)/Fs,length(modY));
subplot(2,1,1); plot(t(1:100),modY(1:100));
modFreqY = fft(modY,N);
len = length(modFreqY);
w = ((0:(len-1)) - len/2) / len * 2;
subplot(2,1,2); plot(w, fftshift(abs(modFreqY)));
title('Mod');

