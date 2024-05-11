clear all; close all; clc;

% Parameters
signal_frequency = 100;         % Frequency of the sinusoidal waveform (in Hz)
carrier_frequency = 100000;       % Frequency of the carrier waveform (in Hz)
peak_voltage = 220 * sqrt(2);    % Peak voltage of the sinusoidal waveform (in V)
carrier_amplitude = 353;         % Amplitude of the carrier waveform (in V)

% Time and frequency parameters
time_step = 0.000000001;         % Time step (1 ns)
angular_frequency = 2 * pi * signal_frequency;  % Angular frequency of the sinusoidal waveform
total_time = 1 / signal_frequency;               % Total simulation time (1 cycle of the sinusoidal waveform)
time_vector = 0:time_step:total_time;            % Time vector from 0 to 1 cycle at dt intervals

% Generating the reference sinusoidal waveform
reference_voltage = peak_voltage * sin(angular_frequency * time_vector);

% Generating the carrier waveform
carrier_voltage = carrier_amplitude * sawtooth(2 * pi * carrier_frequency * time_vector, 0.5);

% Demodulation process: Comparing carrier waveform with sinusoidal waveform
demodulated_voltage = zeros(size(time_vector));  % Initialize demodulated signal

for idx = 1:length(time_vector)
    if carrier_voltage(idx) <= reference_voltage(idx)
        demodulated_voltage(idx) = peak_voltage;   % When carrier <= reference, set demodulated voltage to peak_voltage
    else
        demodulated_voltage(idx) = -peak_voltage;  % When carrier > reference, set demodulated voltage to -peak_voltage
    end
end

% Converting the demodulated signal to a binary PWM signal (0 or 1)
binary_pwm_signal = zeros(size(demodulated_voltage));  % Initialize PWM signal

for idx = 1:length(demodulated_voltage)
    if demodulated_voltage(idx) > 0
        binary_pwm_signal(idx) = 1;   % Set PWM signal to 1 when demodulated voltage > 0
    else
        binary_pwm_signal(idx) = 0;   % Set PWM signal to 0 when demodulated voltage <= 0
    end
end

% Plotting the reference and carrier waveforms
figure;
plot(time_vector, reference_voltage, 'LineWidth', 2);   % Plot the reference sinusoidal waveform
hold on;
plot(time_vector, carrier_voltage, 'LineWidth', 2);      % Plot the carrier waveform

xlabel('Time (s)');
ylabel('Voltage (V)');
title('Sine Pulse Width Modulation (PWM)');

legend('Reference Sinusoid', 'Carrier Waveform');
hold on;
grid on;

% Counting '1's in each cycle of the carrier frequency and processing for PWM
samples_per_cycle = round((1 / carrier_frequency) / time_step);  % Number of samples per carrier cycle
total_cycles = round(total_time * carrier_frequency);            % Total number of carrier cycles

pulse_count_per_cycle = zeros(1, total_cycles);  % Initialize array to store count of '1's per carrier cycle

% Counting '1's in each carrier cycle
for cycle_idx = 0:total_cycles-1
    for sample_idx = cycle_idx * samples_per_cycle + 1 : cycle_idx * samples_per_cycle + samples_per_cycle
        if binary_pwm_signal(sample_idx) == 1
            pulse_count_per_cycle(cycle_idx + 1) = pulse_count_per_cycle(cycle_idx + 1) + 1;
        end
    end
end

% Scaling pulse_count_per_cycle to match a specified range and limiting its maximum value
max_pulse_count = 720;
scaled_pulse_count = round(pulse_count_per_cycle * max_pulse_count / samples_per_cycle);
scaled_pulse_count(scaled_pulse_count > max_pulse_count) = max_pulse_count;
complementary_pulse_count = max_pulse_count - scaled_pulse_count;

% Displaying pulse counts for PWM sequences
fprintf('High Pulse Count (Bang P):\n');
fprintf('\n');

for countA = 1:length(scaled_pulse_count)
    elementStr = num2str(scaled_pulse_count(countA));
    fprintf(elementStr);
    fprintf(', ');

    % Print a new line every 20 elements
    if mod(countA, 20) == 0
        fprintf('\n');
    end
end

fprintf('\n\n');

fprintf('Low Pulse Count (Bang T):\n');
fprintf('\n');

for countA = 1:length(complementary_pulse_count)
    elementStr = num2str(complementary_pulse_count(countA));
    fprintf(elementStr);
    fprintf(', ');

    % Print a new line every 20 elements
    if mod(countA, 20) == 0
        fprintf('\n');
    end
end

fprintf('\n\n');

% Plotting scaled pulse counts for PWM sequences
figure;
plot(scaled_pulse_count);
hold on;
plot(complementary_pulse_count);

xlabel('Cycle Index');
ylabel('Pulse Count');
title('PWM Pulse Counts');

legend('High Pulse Count', 'Low Pulse Count');
hold on;
grid on;