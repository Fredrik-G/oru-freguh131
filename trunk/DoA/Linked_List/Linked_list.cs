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
            throw new NotImplementedException();
        }

        public bool Contains(T item)
        {
            throw new NotImplementedException();
        }

        public void CopyTo(T[] array, int arrayIndex)
        {
            throw new NotImplementedException();
        }

        public int Count
        {
            get { throw new NotImplementedException(); }
        }

        public bool IsReadOnly
        {
            get { throw new NotImplementedException(); }
        }

        public bool Remove(T item)
        {
            throw new NotImplementedException();
        }

        public IEnumerator<T> GetEnumerator()
        {
            throw new NotImplementedException();
        }

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }
        #endregion

        private class Node<T>
        {
            public T value = default(T);
            public Node<T> next = null;
            public Node<T> prev = null;

            public Node() { next = null; }
            public Node(T t)
            {
                value = t;
            }
        }
        private Node<T> head = null;
        private Node<T> tail = null;
        private int count = 0;
        public Linked_list() { head = null; }

        public bool empty() { return head == null; }
        public void PushFront(T v)
        {
            Node<T> n = new Node<T>(v);
            n.next = head;
            head = n;
        }
        public T PopFront()
        {
            if (!empty())
                throw new Exception("ForwardList.Pop: Empty list");

            Node<T> n = head;
            head = head.next;
            return n.value;
        }
        public T Front()
        {
            if (!empty())
                throw new Exception("ForwardList.Front: Empty list");

            return head.value;
        }
    }
}