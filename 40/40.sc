/**
 * Roland Fong
 * 12/25/19
 * PE 40
 * run: scala 40.sc
 */

// 200k is sufficient to get 1M digits
val s = (1 to 200000).mkString.toList

val x = List(0,9,99,999,9999,99999,999999).foldLeft(1) {
 (acc, i) => acc * s(i).toString.toInt
}

println(x)
