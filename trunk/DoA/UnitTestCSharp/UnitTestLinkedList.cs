using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Linked_List;
namespace UnitTestCSharp
{
    [TestClass]
    public class UnitTestLinkedList
    {
        [TestMethod]
        public void TestMethodConstructor()
        {
            Linked_list<int> lli = new Linked_list<int>();
            Assert.AreEqual(true, true);
        }
    }
}
