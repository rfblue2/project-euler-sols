/**
 * Roland Fong
 * 4/20/19
 * PE 39
 * run: scala 39.sc
 */
val p = 1000

val triples = for {
  a <- 1 to p
  b <- 1 to Math.min(a,(p - a))
  c <- 1 to Math.min(b, (p - a - b))
  if a * a == b*b + c*c 
} yield a+b+c

val agg = triples
  .groupBy(identity)
  .mapValues(_.map(_ => 1).reduce(_ + _))

println(agg.maxBy(_._2)._1)
