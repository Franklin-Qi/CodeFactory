#!/bin/sh
###########################################################################
##                                                                       ##
##                  Centre for GTK Technology Learning                   ##
##                Standard Software of China (CS2C), CN                  ##
##                         Copyright (c) 2019                            ##
##                        All Rights Reserved.                           ##
##                                                                       ##
##  Permission is hereby granted, free of charge, to use and distribute  ##
##  this software and its documentation without restriction, including   ##
##  without limitation the rights to use, copy, modify, merge, publish,  ##
##  distribute, sublicense, and/or sell copies of this work, and to      ##
##  permit persons to whom this work is furnished to do so, subject to   ##
##  the following conditions:                                            ##
##   1. The code must retain the above copyright notice, this list of    ##
##      conditions and the following disclaimer.                         ##
##   2. Any modifications must be clearly marked as such.                ##
##   3. Original authors' names are not deleted.                         ##
##   4. The authors' names are not used to endorse or promote products   ##
##      derived from this software without specific prior written        ##
##      permission.                                                      ##
##                                                                       ##
##  THE STANDARD SOFTWARE OF CHINA AND THE CONTRIBUTORS TO THIS WORK     ##
##  DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING      ##
##  ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT   ##
##  SHALL THE CS2C NOR THE CONTRIBUTORS BE LIABLE     ##
##  FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES    ##
##  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN   ##
##  AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,          ##
##  ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF       ##
##  THIS SOFTWARE.                                                       ##
##                                                                       ##
###########################################################################
#                                                                         #
# Run a GTK Technology Learning                                           #
#                                                                         #
###########################################################################


. color.sh

echo_color(){
    msg=$1
    color=$2
    if [ -z $color ]; then
        color=$GREEN
    fi
    echo -e "$color$msg$NONE"
}

usage() {
    echo ""
    echo_color "********************************************"  $RED
    echo_color "     This scripts is for compiling, updating"  $RED
    echo_color "********************************************"  $RED

    echo ""
    echo_color "Usage:" $YELLOW
    echo_color "       ./autogen.sh [option] "  $PURPLE
    echo ""

    echo_color "Common option: " $YELLOW
    echo_color "       install" $BLUE
    echo_color "       clean" $BLUE
    echo ""

    exit
}

mkdir -p ~/.local/share/applications
sed -e "s#@bindir@#$PWD#" org.gtk.exampleapp.desktop \
  > ~/.local/share/applications/org.gtk.exampleapp.desktop

mkdir -p ~/.local/share/icons/hicolor/48x48/apps
cp exampleapp.png ~/.local/share/icons/hicolor/48x48/apps

# automake option
if [ $# -lt 1 ]; then
    usage
fi

case "$1" in
-h* | -\? ) usage
    ;;

"install" )
    make -f Makefile.example
    ;;

"clean" )
    make clean -f Makefile.example
    ;;

* )		
    break
    ;;
esac


