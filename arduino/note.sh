chmod +x motor_control.py

# Add alias to ~/.bashrc
echo "alias forward='python3 /path/to/motor_control.py W'" >> ~/.bashrc
echo "alias backward='python3 /path/to/motor_control.py S'" >> ~/.bashrc
source ~/.bashrc

# Now just type:
#forward
#backward

