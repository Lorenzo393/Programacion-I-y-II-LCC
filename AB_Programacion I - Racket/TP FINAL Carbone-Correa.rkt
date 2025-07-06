;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-intermediate-lambda-reader.ss" "lang")((modname TP5-Carbone-Correa) (read-case-sensitive #t) (teachpacks ((lib "image.rkt" "teachpack" "2htdp") (lib "universe.rkt" "teachpack" "2htdp"))) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ((lib "image.rkt" "teachpack" "2htdp") (lib "universe.rkt" "teachpack" "2htdp")) #f)))
;TP Programacion - Damian Carbone , Lorenzo Correa

; Defino la clave del Codigo de Cesar y su alfabeto
(define ALFABETO "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ 0123456789")
(define CLAVE 3)

; representaremos alfabetos como Strings.
; Por ejemplo, si nuestros símbolos son las cinco primeras letras, los dígitos y el espacio,
; lo representaremos como "ABCDE0123456789 "

; representaremos símbolos como strings de longitud 1. En el alfabeto anterior,
; el símbolo E lo representamos con el string "E"

; el código del césar lo representaremos mediante parejas de símbolos.
; Por ejemplo, si queremos decir que el símbolo "A" se codifica con el
; símbolo "C", tendremos (make-Tupla "A" "C") para representar esta situación.

;;;;;;;; Primero comenzamos definiendo algunas funciones
; sobre strings y listas que nos son de utilidad.

; partir : String -> Listof String
; dado un string, devuele una lista de strings con cada símbolo separado

(define (partir xs)
  (cond [(= (string-length xs) 0) empty]
        [else (cons (substring xs 0 1) (partir (substring xs 1 (string-length xs))))]))

(check-expect (partir "ABC") (list "A" "B" "C"))
(check-expect (partir "X") (list "X"))
(check-expect (partir "12345") (list "1" "2" "3" "4" "5"))
(check-expect (partir "") empty)

; tomar : (Listof Natural) Natural -> (Listof Natural)
; dada una lista y un número natural n, devuelve una lista
; con los primeros n elementos de l. Si l no tiene tantos elementos,
; devuelve l.

(define (tomar ln n)
  (cond [(empty? ln) empty]
        [(zero? n) empty]
        [(positive? n) (cons (first ln) (tomar (rest ln) (sub1 n)))]
        ))

(check-expect (tomar (list 1 2 3 4 5) 4) (list 1 2 3 4))
(check-expect (tomar (list 1 2 3 4 5) 10) (list 1 2 3 4 5))
(check-expect (tomar (list 1 2 3 4 5) 0) empty)
(check-expect (tomar empty 5) empty)

; tirar : (Listof Natural) Natural -> Listof Natural
; dada una lista y un número natural n, devuelve una lista
;  sin los primeros n elementos de l. Si l no tiene tantos elementos,
; devuelve empty.

(define (tirar ln n)
  (cond [(empty? ln) empty]
        [(zero? n) ln]
        [(positive? n) (tirar (rest ln) (sub1 n))]
        ))

(check-expect (tirar (list 1 2 3 4 5) 2) (list 3 4 5))
(check-expect (tirar (list 1 2 3 4 5) 10) empty)
(check-expect (tirar (list 1 2 3 4 5) 0) (list 1 2 3 4 5))
(check-expect (tirar empty 3) empty)

; OBSERVACION: para cualquier n <= length l, (append (tomar n l) (tirar n l)) = l

(define-struct Tupla [f s])
; Tupla es [Any Any]
; que representa un par de elementos de cualquier tipo.  

; emparejar : (Listof X) (Listof Y) -> Listof Tuplas
; dadas dos listas [a0,..., an] y [b0, ...., bn] de la misma longitud, devuelve una lista
; de tuplas con parejas tomadas de ambas listas: [(make-posn a0 b0), ...., (make-posn an bn)]

(define (emparejar lx ly)
  (cond [(and (empty? lx) (empty? ly)) empty]
        [else (cons (make-Tupla (first lx) (first ly)) (emparejar (rest lx) (rest ly)))]
        ))


(check-expect (emparejar empty empty) empty)
(check-expect (emparejar (list "a" 2) (list "b" 4)) (list (make-Tupla "a" "b") (make-Tupla 2 4)))
(check-expect (emparejar (list "h" "l") (list "o" "a")) (list (make-Tupla "h" "o") (make-Tupla "l" "a")))


;;;;;;;;;;;;; Ahora comienzan las funciones específicas para el método del César
; cifrado : N String -> Listof Tupla
; dada una clave de desplazamiento y un alfabeto s, devuelve una lista
; con parejas de strings, donde el primer elemento es el caracter a cifrar, y el segundo
; su código del César de acuerdo a la clave. Se asume que 0 < n < (string-length s)

(define (cifrado n xs)
  (emparejar (partir xs) (append (tirar (partir xs) n) (tomar (partir xs) n) )) 
  )

(check-expect (cifrado 2 "ABC") (list (make-Tupla "A" "C") (make-Tupla "B" "A") (make-Tupla "C" "B"))) 
(check-expect (cifrado 1 "ABC") (list (make-Tupla "A" "B") (make-Tupla "B" "C") (make-Tupla "C" "A")))
(check-expect (cifrado 4 "ABCDEFG") (list (make-Tupla "A" "E") (make-Tupla "B" "F") (make-Tupla "C" "G") (make-Tupla "D" "A") (make-Tupla "E" "B") (make-Tupla "F" "C") (make-Tupla "G" "D")))

; Defino el cifrado completo del Codigo de Cesar
(define CODIGO-DEL-CESAR (cifrado CLAVE ALFABETO))

; encriptar-simbolo : String (Listof Tupla) -> String
; dado un string s de longitud 1 que es un símbolo del
; alfabeto y una lista de parejas que representa un código del césar,
; devuelve el código que le corresponde a s

(define (encriptar-simbolo s xss)
  (Tupla-s (first
   (filter (local ( (define (pareja a) (string=? s (Tupla-f a)) ) ) pareja)
    xss
    )
   )
           )
)

(check-expect (encriptar-simbolo "A" (cifrado 2 "ABC")) "C")
(check-expect (encriptar-simbolo "A" (cifrado 1 "ABC")) "B")
(check-expect (encriptar-simbolo "A" CODIGO-DEL-CESAR) "D")
(check-expect (encriptar-simbolo "Z" CODIGO-DEL-CESAR) "1")

; encriptar-mensaje : String String Natural -> String
; dado un string, un alfabeto y una clave, devuelve el string encriptado

(define (encriptar-mensaje xss abc key)
   (foldr string-append "" (local (
             (define (cript xs)
               (cond [(empty? xs) empty]
                     [(cons? xs) (cons (encriptar-simbolo (first xs) (cifrado key abc)) (cript (rest xs)))] 
                )
             )
            )
       (cript (partir xss))
     )
   ) 
)

(check-expect (encriptar-mensaje "ABC" "ABCDEF" 3) "DEF")
(check-expect (encriptar-mensaje "ABC" "ABCDEF" 4) "EFA")
(check-expect (encriptar-mensaje "ESTO NO ES UN MENSAJE CIFRADO" ALFABETO CLAVE) "HVWR2PR2HV2XP2OHPVDMH2FLIUDGR")


; desencriptar-simbolo : String (Listof Tupla) -> String
; dado un string s de longitud 1 que es un símbolo del
; alfabeto y una lista de parejas que representa un código del césar,
; devuelve el caracter desencriptado que le corresponde a s

(define (desencriptar-simbolo s xss)
  (Tupla-f (first
   (filter (local ( (define (pareja a) (string=? s (Tupla-s a)) ) ) pareja)
    xss
    )
   )
  )
)

(check-expect (desencriptar-simbolo "A" (cifrado 2 "ABC")) "B")
(check-expect (desencriptar-simbolo "A" (cifrado 1 "ABC")) "C")
(check-expect (desencriptar-simbolo "D" CODIGO-DEL-CESAR) "A")
(check-expect (desencriptar-simbolo " " CODIGO-DEL-CESAR) "X")


; desencriptar-mensaje : String String Natural -> String
; dado un string, un alfabeto y una clave, devuelve el string encriptado

(define (desencriptar-mensaje xss abc key)
   (foldr string-append "" (local (
             (define (cript xs)
               (cond [(empty? xs) empty]
                     [(cons? xs) (cons (desencriptar-simbolo (first xs) (cifrado key abc)) (cript (rest xs)))] 
                )
             )
            )
       (cript (partir xss))
     )
   ) 
)

(check-expect (desencriptar-mensaje "DEF" "ABCDEF" 3) "ABC")
(check-expect (desencriptar-mensaje "EFA" "ABCDEF" 4) "ABC")
(check-expect (desencriptar-mensaje (encriptar-mensaje "ESTO NO ES UN MENSAJE CIFRADO" ALFABETO CLAVE) ALFABETO CLAVE) "ESTO NO ES UN MENSAJE CIFRADO")



; evaluamos las siguientes expresiones:
(encriptar-mensaje "HOLA" ALFABETO CLAVE)
(encriptar-mensaje "ATACAR A LAS 18" ALFABETO CLAVE)
(encriptar-mensaje "LA OPERACION ES REVERSIBLE" ALFABETO CLAVE)
(desencriptar-mensaje (encriptar-mensaje "LA OPERACION ES REVERSIBLE" ALFABETO CLAVE) ALFABETO CLAVE)

; obtenemos:
; "KRÑD"
; "DWDFDU2D2ÑDV24B"
; "ÑD2RSHUDFLRP2HV2UHYHUVLEÑH"
; "LA OPERACION ES REVERSIBLE"
(check-expect (encriptar-mensaje "HOLA" ALFABETO CLAVE) "KRÑD")
(check-expect (encriptar-mensaje "ATACAR A LAS 18" ALFABETO CLAVE) "DWDFDU2D2ÑDV24B")
(check-expect (encriptar-mensaje "LA OPERACION ES REVERSIBLE" ALFABETO CLAVE) "ÑD2RSHUDFLRP2HV2UHYHUVLEÑH")
(check-expect (desencriptar-mensaje (encriptar-mensaje "LA OPERACION ES REVERSIBLE" ALFABETO CLAVE) ALFABETO CLAVE) "LA OPERACION ES REVERSIBLE")