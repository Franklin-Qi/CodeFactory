# .bashrc

# Source global definitions
if [ -f /etc/bashrc ]; then
    . /etc/bashrc
fi


# Function toc-md: help gh-md-toc to generate dir
function md-toc {
    echo "$(gh-md-toc  $1)" >> $1
}

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

# User specific aliases and functions
# smb://10.1.80.80/loongson/mipsDoc/shuoqi.yu qwer1234

# ps -ef
alias myps='ps -ef | grep '

# cman
alias cman='man -M /usr//share/man/zh_CN'
export LC_CTYPE=zh_CN.UTF-8

# mysql
alias mysqllogin='mysql -udebian-sys-maint -pMTiXp6Dt0Oe1ct2F'

# color
alias ls='ls --color '
alias grep='grep --color '

# .bashrc
alias vib='vim ~/.bashrc'
alias srcb='source ~/.bashrc'

# vim
alias vi='vim '
alias vifile='cd ~/; vim '

# cd
alias cdrpmbuild='cd ~/rpmbuild/'
alias cdbuild='cd ~/rpmbuild/BUILD/'
alias cdhome='cd ~/'
alias myturn='cd -'
alias ..='cd ../'
alias ..2='cd ../../'
alias ..3='cd ../../../'
alias cdcodefactory='cd /home/yusq/CodeFactory '

# git
alias gitpush='git push origin HEAD:refs/for/master'
alias buildbp='rpmbuild -bp -D "_topdir `pwd`" '
alias buildba='rpmbuild -ba -D "_topdir `pwd`" '
alias buildbs='rpmbuild -bs -D "_topdir `pwd`" '

# ssh
alias sshloongson='ssh yusq@10.1.81.129' # ']\
alias ssharm='ssh yusq@10.1.81.206'
alias sshl2='ssh root@10.1.81.202 -X' # 1

# nohup stardict
alias nohupstardict='nohup  stardict  >/dev/null 2>&1 &'

# software-center
alias cdsoftware='cd /usr/share/doc/software-center/'

# mutter
alias mygrep='grep -nr '
alias myschemas='sudo glib-compile-schemas schemas/'
alias cdglib='cd /usr/share/glib-2.0/'
alias vibindings='sudo vim schemas/org.gnome.desktop.wm.keybindings.gschema.xml'
alias cdmutter='cd ~/rpmbuild/BUILD/mutter-3.14.4/'
alias vimutter='cd ~/rpmbuild; vim SPECS/mutter.spec'
alias vikey='cd  ~/rpmbuild/BUILD/mutter-3.14.4/; vim src/core/keybindings.c'
alias viwin='vim src/core/window.c'
alias mutterbp='rpmbuild -bp SPECS/mutter.spec'
alias mutterba='rpmbuild -ba SPECS/mutter.spec'
alias cpa='cp mutter-3.14.4/ bak -a'
alias mydiff='diff -Nura bak/ mutter-3.14.4/ > '

