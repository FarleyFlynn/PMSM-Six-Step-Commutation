clear all; close all; clc;
M = csvread('Res1.csv');
format long
time=M(:,1);
S=M(:,2);
C=M(:,3);
sinTheta=S-mean(S);
cosTheta=C-mean(C);

figure(); %figure 1
plot(time,sinTheta);
hold on;
plot(time,cosTheta);
legend('sine','cosine')
grid on
grid minor


Ntime=length(time);
T=time(Ntime)-time(1);
dt=T/Ntime;
Nc=round(0.02/dt);
Np=round(0.02/dt/4);
Dem=0;
MaxDem=round(length(time)/Nc);
for count=1:MaxDem
    PeakSine(Dem+1)=sinTheta(Np+Nc*Dem);
    PeakCos(Dem+1)=cosTheta(Np+Nc*Dem);
    PeakTime(Dem+1)=time(Np+Nc*Dem);
    Dem=Dem+1;
end
figure(); %figure 2
plot(PeakTime,PeakSine);
hold on;
plot(PeakTime,PeakCos);
legend('sine','cosine')
grid on
grid minor


figure(); %figure 3
plot(time,sinTheta);
hold on;
plot(time,cosTheta);
plot(PeakTime,PeakSine);
plot(PeakTime,PeakCos);
legend('sine','cosine')
grid on
grid minor

tanTheta=PeakSine./PeakCos;
figure(); %figure 4
plot(PeakTime,tanTheta);
grid on
grid minor

Y=atan(tanTheta)*180/pi;
figure(); %figure 5
plot(PeakTime,Y);
grid on
grid minor

figure(); %figure 6
subplot(3,1,1);
plot(time,sinTheta);
grid on
grid minor
subplot(3,1,2);
plot(time,cosTheta);
grid on
grid minor
subplot(3,1,3);
plot(PeakTime,tanTheta);
grid on
grid minor


figure(); %figure 7
subplot(2,1,1);
plot(time,sinTheta);
hold on;
plot(time,cosTheta);
grid on
grid minor
subplot(2,1,2);
plot(PeakTime,Y);
hold on;
plot(PeakTime,Y,'*');
grid on
grid minor
%}
