Данная программа поможет определить кратность произвольной строки определенному значению.  
В качестве входных данных пользователю необходимо ввести строку и коэффициент.  
Алгоритм работы:
1. программа проверяет правильность длины строки относительно коэффициента;  
2. после этого из строки выделяется объект размером, равным коэффициенту;
3. происходит первичное сравнение первых символов объекта и сегментов строки (для экономии времени и ресурсов); 
4. на заключительном этапе происходит проверка всех оставшихся символов объекта с сегментами строки (в циклах) с помощью алгоритма Бойера-Мура-Хорспула (есть также реализация с наивным поиском).
