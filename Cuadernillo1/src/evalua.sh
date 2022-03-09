for FILE in */tad*.cpp ; do
    echo "Evaluando $FILE"
    cp $FILE main.cpp
    cd ..
    make
    cd src
    ../main > $FILE.out
    diff -b -B -i $FILE.out $FILE.sal
    if [ "$?" == "0" ]; then
        echo "OK"
    else
        echo "ERROR"
    fi
done