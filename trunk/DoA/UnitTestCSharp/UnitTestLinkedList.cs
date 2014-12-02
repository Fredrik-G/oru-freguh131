using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Linked_List;
namespace UnitTestCSharp
{
    [TestClass]
    public class UnitTestLinkedList
    {
        [TestMethod]
        public void TestLinkedListConstructor()
        {
            Linked_list<int> lli = new Linked_list<int>();
            Assert.AreEqual(true, lli.Empty());
        }
        [TestMethod]
        public void TestLinkedListAddFirstAndLast()
        {
            Linked_list<int> lli = new Linked_list<int>();
            lli.AddLast(10);
            lli.AddLast(20);
            Assert.AreEqual(false, lli.Empty());
            Assert.AreEqual(10, lli.First);
            lli.AddFirst(30);
            Assert.AreEqual(30, lli.First);
            Assert.AreEqual(20, lli.Last);
        }
        [TestMethod]
        public void TestLinkedListRemoveFirstAndLast()
        {
            Linked_list<char> llc = new Linked_list<char>();
            llc.AddLast('A');
            llc.AddLast('B');
            llc.AddLast('C');

            llc.RemoveFirst();
            Assert.AreEqual('B', llc.First);
            llc.RemoveFirst();
            Assert.AreEqual('C', llc.First);

            llc.AddLast('D');
            llc.AddLast('F');

            Assert.AreEqual('F', llc.Last);
            llc.RemoveLast();
            llc.RemoveLast();
            Assert.AreEqual('C', llc.Last);
        }
        [TestMethod]
        public void TestLinkedListClear()
        {
            Linked_list<int> lli = new Linked_list<int>();
            lli.AddLast(1);
            lli.AddLast(2);
            lli.AddLast(3);

            Assert.AreEqual(false, lli.Empty());
            lli.Clear();
            Assert.AreEqual(true, lli.Empty());
            lli.AddLast(4);
            Assert.AreEqual(4, lli.First);
            Assert.AreEqual(4, lli.Last);
        }
        [TestMethod]
        public void TestLinkedListCount()
        {
            Linked_list<int> lli = new Linked_list<int>();
            for (int i = 0; i < 20; i++)
                lli.AddLast(i);

            Assert.AreEqual(20, lli.Count);
        }
        [TestMethod]
        public void TestLinkedListContains()
        {
            Linked_list<int> lli = new Linked_list<int>();
            for (int i = 0; i < 20; i++)
                lli.AddLast(i);

            Assert.AreEqual(true, lli.Contains(10));
            Assert.AreEqual(true, lli.Contains(11));
            Assert.AreEqual(false, lli.Contains(21));
        }
        [TestMethod]
        public void TestLinkedListFind()
        {
            Linked_list<int> lli = new Linked_list<int>();
            for (int i = 0; i < 20; i++)
                lli.AddLast(i);

            Assert.AreEqual(10, lli.Find(10));
            Assert.AreEqual(0, lli.Find(50));
        }
        [TestMethod]
        public void TestLinkedListRemove()
        {
            Linked_list<int> lli = new Linked_list<int>();
            for (int i = 0; i < 20; i++)
                lli.AddLast(i);
            
            //Ta bort första elementet
            lli.Remove(0);
            Assert.AreEqual(0, lli.Find(0));
            //Ta bort element i mitten
            lli.Remove(10);
            Assert.AreEqual(9, lli.Find(9));
            Assert.AreEqual(0, lli.Find(10));
            //Ta bort sista elementet
            lli.Remove(19);
            Assert.AreEqual(0, lli.Find(19));
        }
    }
}
