Программа предоставляет функцию generateRandomPassword(), которая генерирует случайный набор символов с указанной длиной. Функция использует статические переменные, чтобы сохранить состояние генератора псевдослучайных чисел между вызовами.

Функции fileExists(), readLinesFromFile() и writeLinesToFile() предоставляют функциональность для работы с файлами.

В функции main() считываются строки файла "videostreams.txt" в вектор loginLines. Затем проверяется, существует ли файл "videostreams.txt". Если да, то его содержимое считывается в вектор passwdLines. Затем программа проверяет, нужно ли дописать строки в "videostreams_channels.txt" или уменьшить его размер до количества строк в "videostreams_channels.txt". Если требуется дописать строки, генерируются соответствующие пароли и добавляются в passwdLines.

Наконец, passwdLines записывается обратно в файл "videostreams_channels.txt".


Для работы программы потребуется ffmpeg, скачать можно отсюда: https://ffmpeg.org/ Инструкция по установке ffmpeg: https://www.youtube.com/watch?v=2eSRuadzJxA

Компилятор можно скачать отсюда: https://jmeubank.github.io/tdm-gcc/download/ или отсюда: https://www.embarcadero.com/free-tools/dev-cpp

Для проверки установлен ли компилятор, ввести в командную строку: g++ -v

Для компиляции программы: перейти в каталог с исходником и ввести в командную строку:

Linux:

g++ -std=c++11 -o ffrtmp ffrtmp.cpp

Win:

g++ -std=c++11 -o ffrtmp.exe ffrtmp.cpp
