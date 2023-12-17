#!/bin/sh
#
# apply_patch.sh - Applies an enhancement patch
#

read -p "Do you wish to apply the patch '$1'? [Y/N] " response
case "$response" in
    Y|y)
	patch -p1 < "$1"
	;;
    N|n)
	echo 'Quit'
	exit 1
	;;
    *)
	echo "Invalid response '$response'."
	exit 1
	;;
esac

