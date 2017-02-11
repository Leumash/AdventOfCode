import scala.io.Source._
import Math._

val lines = stdin.getLines
val regex = "[0-9]+".r

val lengthsOfSides = lines map (line => regex.findAllIn(line).toList) map (_ match { case List(a,b,c) => (a.toInt,b.toInt,c.toInt)})

val surfaceAreas = lengthsOfSides map {
    case (a,b,c) => (a * b, a * c, b * c)
}

val totalWrapping = surfaceAreas map {
    case (a,b,c) => {
        min(min(a,b),c) + a * 2 + b * 2 + c * 2
    }
}

val total = totalWrapping.sum

println(total)

