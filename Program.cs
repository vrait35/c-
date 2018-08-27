using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            FirstTask();
            SecondTask();
            ThirdTask();
            FourTask();
            Console.ReadKey();
            Console.Clear();
            FiveTask();
            SixTask();
            SevenTask();
            EightTask();
        }

        private static void SecondTask()
        {
            Console.WriteLine("2.Дан радиус окружности. Найти длину окружности и площадь круга.");
            Console.WriteLine("Введите радиус окружности: ");
            double Radius = int.Parse(Console.ReadLine());
            const double PI_NUMBER = 3.14;
            double circumference = 2 * PI_NUMBER * Radius;
            double Area = PI_NUMBER * Radius * Radius;
            Console.WriteLine("Длина окружности: " + circumference + " \nПлощадь круга: " + Area);
        }

        private static void FirstTask()
        {
            Console.WriteLine("1.вычисления значения функции y = 7x ^ 2 - 3x + 4  при любом значении x;");
            Console.WriteLine("Введите число х: ");
            var x = double.Parse(Console.ReadLine());
            const int a = 7;
            const int b = -3;
            const int c = 4;
            double y = a * x * x + b + c;
            Console.WriteLine("y = " + y);
        }
        static private void ThirdTask()
        {
            Console.WriteLine("3.Дано расстояние в сантиметрах.Найти число полных метров в нем.");
            Console.WriteLine("Введите сантиметры: ");
            double SantiMetr = double.Parse(Console.ReadLine());
            double hundred = 100;
            double Metr = SantiMetr / hundred;
            Console.WriteLine("метров: " + Metr);
        }
        static private void FourTask()
        {
            Console.WriteLine("4.С некоторого момента прошло 234 дня.Сколько полных недель прошло за этот период ?");
            int day = 234;
            int weekIsDay = 7;
            int weekCount = (day / weekIsDay);
            Console.WriteLine("Количество полных недель: " + weekCount);
        }
        static private void FiveTask()
        {
            Console.WriteLine("5.Дано двузначное число. Найти: " +
                "\na.число десятков в нем;\nb.число единиц в нем;\nc.сумму его цифр;" +
            "\nd.произведение его цифр");
            Console.WriteLine("Введите двузначное число: ");
            int twoNumber = int.Parse(Console.ReadLine());
            int buferNumber = twoNumber;
            int CountTen = buferNumber / 10;
            buferNumber = twoNumber;
            int CountOne = buferNumber % 10;
            buferNumber = twoNumber;
            int CountCifr = CountOne + CountTen;
            Console.WriteLine("число десятков: " + CountTen + " \nчисло единиц " + CountOne +
                "\nсуммa цифр  " + CountCifr);
        }
        static private void SixTask()
        {
            Console.WriteLine("6.Дано четырехзначное число. Найти:" +
            "\na.сумму его цифр;" +
            "\nb.произведение его цифр.");
            Console.WriteLine("Введите четырехзначное число: ");
            int FourNumber = int.Parse(Console.ReadLine());
            int bufFourNumber = FourNumber;
            int Sum = 0;
            while (bufFourNumber > 0)
            {
                Sum += bufFourNumber % 10;
                bufFourNumber /= 10;
            }
            bufFourNumber = FourNumber;
            int perfoming = 1;// 
            while (bufFourNumber > 0)
            {
                perfoming *= bufFourNumber % 10;
                bufFourNumber /= 10;
            }
            Console.WriteLine("Сумма его цифр: " + Sum + "\nпроизведение цифр: " + perfoming);
        }
        static private void SevenTask()
        {
            Console.WriteLine("7.	В трехзначном числе x зачеркнули его вторую цифру." +
                " \nКогда к образованному при этом двузначному числу справа приписали" +
                " \nвторую цифру числа x, то получилось число 456. Найти число x.");
            int ResultNumber = 456;
            int hundred = 100;
            int ten = 10;
            int Number1 = ResultNumber / hundred;
            int Number2 = (ResultNumber - Number1 * hundred) / 10;
            int Number3 = ResultNumber % 10;
            int Result = Number1 * hundred + Number3 * ten + Number2;
            Console.WriteLine("Число х = " + Result);
        }
        static private void functionAddEightTask(bool x, bool y)
        {
            Console.WriteLine(" При x= " + x + " и  y= " + y);
            bool result = !x && !y;
            Console.WriteLine("не X и не Y : " + result);
            result = x || (!x && y);
            Console.WriteLine("X или(не X и Y) : " + result);
            result = (!x && y) || y;
            Console.WriteLine("(не X и Y) или Y : " + result);
        }
        static private void EightTask()
        {
            Console.WriteLine("8.Вычислить значение логического выражения при всех возможных значениях логических величин X и Y:" +
             "\na.не X и не Y;" +
            "\nb.X или(не X и Y);" +
            "\nc.  (не X и Y) или Y.");
            bool x = false;
            bool y = false;
            functionAddEightTask(x, y);
            x = true;
            y = true;
            functionAddEightTask(x, y);
            x = false;
            functionAddEightTask(x, y);
            x = true;
            y = false;
            functionAddEightTask(x, y);
        }
    }
}
