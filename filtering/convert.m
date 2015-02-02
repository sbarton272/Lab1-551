%% Convert dat files back to something android knows

[y, Fs] = audioread('hw1_noisy.wav');
fid = fopen('hw1_noisy.dat','w');
fwrite(fid,y,'double');
fclose(fid);

%%

fid = fopen('hw1_noisy.dat', 'r');
y1 = fread(fid, size(y), 'double');
fclose(fid);

fid = fopen('hw1_filtered.dat', 'r');
y2 = fread(fid, size(y), 'double');
fclose(fid);

fid = fopen('hw1_modulated.dat', 'r');
y3 = fread(fid, size(y), 'double');
fclose(fid);

%sound(y1, Fs); pause;
%sound(y2, Fs); pause;
%sound(y3, Fs);

%% Save back as wav

audiowrite('hw1_noisy.mp4',y1,Fs);
audiowrite('hw1_filtered.mp4',y2,Fs);
audiowrite('hw1_modulated.mp4',y3,Fs);

