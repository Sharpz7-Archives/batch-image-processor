#/bin/bash

# Uninstall any previous versions.
echo "Checking for any previous version..."
sudo rm -r /usr/local/bin/ bimgproc

# Download and unpack
wget https://github.com/Sharpz7/batch-image-processor/releases/download/XXXXX/linux.tar.gz
sudo tar -C /usr/local/bin/ -zxvf linux.tar.gz
rm -r linux.tar.gz

# Permissions
chmod u+x /usr/local/bin/bimgproc

echo ""
echo "The Batch Image Processor IS NOW INSTALLED"
echo "======================="
echo "Do bimgproc -h for more info!"