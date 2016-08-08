import scala.io.Source

object day1 {
    def main(args: Array[String]): Unit = {
        val lines = getStringFromFile("./input.txt")

        def getDifferenceCount(xs: List[Char], aggregate: Int): Int = xs match {
            case Nil => aggregate
            case '(' :: tail => getDifferenceCount(tail, aggregate + 1)
            case ')' :: tail => getDifferenceCount(tail, aggregate - 1)
            case _ => throw new IllegalArgumentException
        }

        println(getDifferenceCount(lines, 0))
    }

    def getStringFromFile(fileName: String): List[Char] = {
        Source.fromFile(fileName).toList
    }
}

