# Лабораторные работы по ООП

## Задание
Блогер Боря пытается сочетать увлечение астрономией с тягой к путешествиям.
Пока пожертвований подписчиков не хватает на билет,
он пытается представить, как выглядит звёздное небо в различных точках земного шара.
Для этого Боре нужна программа,
которая позволяет составить карту звёздного неба,
поворачивать её (с поправкой на долготу)
и отфильтровывать наименее яркие объекты 
(с поправкой на световое загрязнение крупных городов).

1. Небесное тело: небесные координаты; видимая звёздная величина.
2. Система: несколько небесных тел, связанных гравитационно.
3. Карта звёздного неба (массив звёзд и других небесных тел),
класс которой включает следующие методы:
   * метод, принимающий значение угла и возвращающий копию карты звёздного неба,
повёрнутую на заданный угол;
   * метод, принимающий значение звёздной величины и возвращающий копию карты звёздного неба, в которой присутствуют только объекты со звёздной величиной не меньше заданной.
