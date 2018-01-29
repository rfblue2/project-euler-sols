/*
 * Roland Fong
 * 1/29/18
 * Problem 18:
 * We wish to find the maximum sum down a triangle.
 * We will formulate it as a weighted shortest path problem,
 * by finding the shortest path using negative weights
 */
import scala.collection.mutable
import scala.io.Source

// Convert input to array of negative weights
// Use array so we can index into any spot
val inputfile = "/Users/rfong/Documents/workspace/p18/18.txt"
val lines = Source.fromFile(inputfile).getLines().toArray
val nums = lines.flatMap (l => l.split(" ").map(x => -x.toInt))

// height of the triangle
val height = Math.floor(Math.sqrt(nums.length*2)).toInt

// convert a coordinate to index in array (indexed from 0)
def cToIdx (v: (Int, Int)): Int = {
  val (r, c) = v
  r * (r+1) / 2 + c
}

// Convert index to coordinate
def idxToC (idx: Int): (Int, Int) = {
  val r = Math.round(Math.sqrt(idx * 2)).toInt
  val c = idx - r * (r+1) / 2
  (r, c)
}

// Get the weight of the coordinate from the array
def getWeight (v: (Int, Int)): Int = nums(cToIdx(v))

// Get the neighbors of the coordinate
def getNeighbors (v: (Int, Int)): List[(Int, Int)] = {
  if (cToIdx(v) >= nums.length) Nil
  else List((v._1 + 1, v._2), (v._1 + 1, v._2 + 1))
}

// Initialize dijkstra's (all are dist 0 except initial
// which takes the weight it was given)
val initial = (0,0)
val distTo: mutable.Map[(Int, Int), Int] = new mutable.HashMap()
for (
  i <- 0 until height;
  j <- 0 to i
) distTo += (((i,j), 0))
distTo += ((initial, getWeight(initial)))

// distTo updates if the edge decreases dist to vertex
def relax(from: (Int, Int)) (to: (Int, Int)): Unit = {
  if (distTo(to) > distTo(from) + getWeight(to)) {
     distTo += ((to, distTo(from) + getWeight(to)))
  }
}

// "outputs" map of vertices to shortest distance from source
def dijkstra (vs: List[(Int, Int)], row: Int): Unit = vs match {
  case Nil => if (row < height - 2) {
      val newCs = for (c <- 0 to (row+1))
        yield (row+1, c)
      dijkstra(newCs.toList, row+1)
    } else println("Finished")
  case v::tl =>
    getNeighbors(v).foreach(relax(v))
    dijkstra(tl, row)
}

dijkstra(List(initial), 0)

// Go through the last row and find the minimum distance
val dists = for (i <- 0 until height)
  yield distTo((height-1, i))

val minimum = dists.fold(0)(Math.min)

println(-minimum) // the maximum sum
