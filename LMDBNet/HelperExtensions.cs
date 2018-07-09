﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LMDBNet
{
    public static class TestHelperExtensions
    {
        public static void Put(this LMDBTransaction tx, LMDBDatabase db, string key, string value)
        {
            var enc = System.Text.Encoding.UTF8;
            tx.Put(db, enc.GetBytes(key), enc.GetBytes(value));
        }

        public static string Get(this LMDBTransaction tx, LMDBDatabase db, string key)
        {
            var enc = System.Text.Encoding.UTF8;
            var result = tx.Get(db, enc.GetBytes(key));
            return enc.GetString(result);
        }

        public static void Delete(this LMDBTransaction tx, LMDBDatabase db, string key)
        {
            var enc = System.Text.Encoding.UTF8;
            tx.Delete(db, enc.GetBytes(key));
        }

        public static bool ContainsKey(this LMDBTransaction tx, LMDBDatabase db, string key)
        {
            var enc = System.Text.Encoding.UTF8;
            return tx.ContainsKey(db, enc.GetBytes(key));
        }

        public static bool TryGet(this LMDBTransaction tx, LMDBDatabase db, string key, out string value)
        {
            var enc = System.Text.Encoding.UTF8;
            byte[] result;
            var found = tx.TryGet(db, enc.GetBytes(key), out result);
            value = enc.GetString(result);
            return found;
        }

        public static IEnumerable<IEnumerable<T>> Split<T>(this IEnumerable<T> list, int parts)
        {
            return list
                .Select((x, i) => new { Index = i, Value = x })
                .GroupBy(x => x.Index / parts)
                .Select(x => x.Select(v => v.Value));
        }
    }

}