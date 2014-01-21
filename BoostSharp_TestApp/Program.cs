using BoostSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ManagedConsoleApplication
{
	class Program
	{
		private static MatchFlags flags = MatchFlags.G;

		static void Main(string[] args)
		{
			string test = "t";
			string result = Regex.Replace(test, @"\b([a-z])(\w+)?\b", @"\u$1(?2:Doo:Fuu)", MatchFlags.G);
			Console.WriteLine(result);
		}
	}
}
