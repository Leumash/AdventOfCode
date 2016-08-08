import scala.io.Source

object day1 {
    def main(args: Array[String]): Unit = {
        val lines = getStringFromFile("./input.txt")

        val answer = lines.foldLeft(0)((aggregate, char) => char match {
            case '(' => aggregate + 1
            case ')' => aggregate - 1
        })

        println(answer)
    }

    def getStringFromFile(fileName: String): List[Char] = {
        Source.fromFile(fileName).toList
    }
}

