import scala.io.Source

object day1 {
    def main(args: Array[String]): Unit = {
        val lines = getStringFromFile("./input.txt")

        def getWhenSantaFirstEntersBasement(xs: List[Char], location: Int, pos: Int): Int = (location, xs) match {
            case (-1, _) => pos
            case (_, '(' :: tail) => getWhenSantaFirstEntersBasement(tail, location + 1, pos + 1)
            case (_, ')' :: tail) => getWhenSantaFirstEntersBasement(tail, location - 1, pos + 1)
            case (_,_) => throw new IllegalArgumentException
        }

        println(getWhenSantaFirstEntersBasement(lines, 0, 0))
    }

    def getStringFromFile(fileName: String): List[Char] = {
        Source.fromFile(fileName).toList
    }
}

