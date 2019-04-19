/**
 * Roland Fong
 * 4/19/19
 * PE 38
 */
object Hello {
  val digits = "123456789".toSet
  val pandigitals: Seq[String] = List.range(1,10000)
    .flatMap(calcPandigital)
    .filter(verifyPandigital)
  val maxpan: Int = pandigitals.map(p => p.toInt).max

  def calcPandigital(n:Int):Option[String] = {
    def calc(i:Int, acc:String):Option[String] = {
      if (acc.length() > 9) None
      else if (acc.length() == 9) Some(acc)
      else calc(i+1,acc + (n*i).toString)
    }

    calc(1, "")
  }

  def verifyPandigital(n:String): Boolean = n.toSet == digits

  def main(args: Array[String]): Unit = {
    println(maxpan)
  }
}
