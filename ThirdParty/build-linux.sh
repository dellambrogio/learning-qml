#!/bin/sh

cd "${0%/*}"

rm -rf install
mkdir install

for i in * ; do
	if [ -d "$i" ]; then
		echo "$i"
		if [ -f "$i/build-linux.sh" ]; then
			cd "$i"
			./build-linux.sh
			cd ..
		fi
	fi
done