#echo "# c-11" >> README.md
#git init
find ./* -name "*.o" | xargs rm -rf
git add *
git commit -m "87 commit"
#git remote add origin https://github.com/wangzhicheng2013/c-11.git
git push -u origin master
