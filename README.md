Консольный Ping Pong
Простая реализация игры "Ping Pong" на языке C для терминала.
Описание игры
Игра представляет собой классический пинг-понг с двумя ракетками и мячом. Игроки управляют ракетками с помощью клавиш и пытаются отбить мяч, чтобы не пропустить его.
Управление
Игрок 1 (левая ракетка):
A - двигать ракетку вверх
Z - двигать ракетку вниз
Игрок 2 (правая ракетка):
K - двигать ракетку вверх
M - двигать ракетку вниз
Q - выход из игры
Пробел - пропуск хода (мяч продолжает движение)
Особенности реализации
Игровое поле размером 80x25 символов
Счет игроков отображается внизу экрана
Игра продолжается до 21 очка
Простая физика отражения мяча от ракеток
Сборка и запуск
Скомпилируйте программу:
bash
gcc ping_pong.c -o ping_pong
Запустите игру:
bash
./ping_pong
Требования
Компилятор C (gcc, clang)
Терминал, поддерживающий стандартный ввод/вывод
