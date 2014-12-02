using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Linked_List
{
    class Program
    {

        static void Main(string[] args)
        {
            Linked_list<int> lli = new Linked_list<int>();
            lli.AddLast(1);
            lli.AddLast(2);
            lli.AddLast(3);
            lli.AddFirst(4);
            Console.WriteLine(lli.Last);
            Console.WriteLine(lli.First);
            Console.WriteLine("hej");
            Console.ReadLine();
        }
    }
}
