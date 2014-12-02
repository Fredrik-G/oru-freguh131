using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Linked_List
{
    public class Linked_list<T> : ICollection<T>
    {
        #region ICollection
        public void Add(T item)
        {
            throw new NotImplementedException();
        }

        public void Clear()
        {
            head = tail = null;
        }

        public bool Contains(T value)
        {
            foreach(var item in this)
            {
                if (item.Equals(value) == true)
                    return true;                  
            }
            return false;
        }
        public T Find(T value)
        {
            foreach (var item in this)
            {
                if (item.Equals(value) == true)
                    return item;
            }
            return default(T);
        }
        public void CopyTo(T[] array, int arrayIndex)
        {
            throw new NotImplementedException();
        }
        public int Count
        {
            get
            {
                foreach (var item in this)
                {
                    count++;
                }
                return count;
            }
        }

        public bool IsReadOnly
        {
            get { throw new NotImplementedException(); }
        }

        public bool Remove(T item)
        {//return true om den lyckas ta bort noden, annars false.
            if (Empty())
                return false;

            Node<T> n = head.next;

            while (n != null)
            {
                if (n.value.Equals(item))
                {                  
                    if(n.next == null)
                    {
                        n.prev.next = null;
                        tail = n.prev;
                        return true;
                    }
                    else if (n.prev == null)
                    {
                        n.next.prev = null;
                        head = n.next;
                        return true;
                    }
                    else
                    {
                        n.prev.next = n.next;
                        n.next.prev = n.prev;
                        return true;
                    }
                }
                n = n.next;
            }
            return false;
        }

        public IEnumerator<T> GetEnumerator()
        {//http://www.codeproject.com/Articles/474678/A-Beginners-Tutorial-on-Implementing-IEnumerable-I
         //Yield kommer ihåg tillstånd och fortsätter vid nästa värde vid nästa anrop (istället för att börja om som vanlig return).
           while(!Empty())
            {
                yield return head.value;
                head = head.next;
            }
        }

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return this.GetEnumerator();
        }
        #endregion

        private class Node<T>
        {
            public T value = default(T);
            public Node<T> next = null;
            public Node<T> prev = null;

            public Node()
            {
                next = prev = null;
            }
            public Node(T t)
            {
                value = t;
            }   
        }
        private Node<T> head = null;
        private Node<T> tail = null;
        private int count = 0;
        public Linked_list() { head = tail = null; }

        public bool Empty() { return head == null; }
        public void AddFirst(T value)
        {
            Node<T> n = new Node<T>(value);
            if (Empty())
                head = tail = n;
            else
            {
                head.prev = n;
                n.next = head;
                head = n;
            }
        }
        public void AddLast(T value)
        {
            Node<T> n = new Node<T>(value);
            if (Empty())
                head = tail = n;
            else
            {
                tail.next = n;
                n.prev = tail;
                tail = n;
            }
        }
        public void RemoveFirst()
        {
            if (Empty())
                throw new Exception("ForwardList.RemoveFirst: Empty list");
            else
            {
                head = head.next;
                if (head == null)
                    tail = null;
                else
                    head.prev = null;
            }
        }
        public void RemoveLast()
        {
            if (Empty())
                throw new Exception("ForwardList.RemoveLast: Empty list");
            else
            {
                tail = tail.prev;
                if (tail == null)
                    head = null;
                else
                    tail.next = null;
            }
        }
        public T First
        {
            get
            {
                if (Empty())
                    throw new Exception("ForwardList.First: Empty list");

                return head.value;
            }
        }
        public T Last
        {
            get
            {
                if (tail == null)
                    throw new Exception("ForwardList.Last: Empty list");

                return tail.value;
            }
        }
        
    }
}