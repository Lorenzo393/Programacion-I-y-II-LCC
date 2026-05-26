;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica 4 - 9|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;Ej 9
(define-struct Img [geo forma color tam])
; Img: (Image, String, String, Number)

(define ESCENA (empty-scene 700 700))
(define INICIAL (Img ESCENA "triangle" "red" 20))

(define (pantalla i)
  (Img-geo i))
              

(define (teclado i k)
  (cond [(string=? k "t") (Img (Img-geo i) "triangle" (Img-color i) (Img-tam i))]
        [(string=? k "c") (Img (Img-geo i) "square" (Img-color i) (Img-tam i))]
        [(string=? k "e") (Img (Img-geo i) "star" (Img-color i) (Img-tam i))]
        [(string=? k "o") (Img (Img-geo i) "circle" (Img-color i) (Img-tam i))]
        [(string=? k "+") (Img (Img-geo i) (Img-forma i) (Img-color i) (+ (Img-tam i) 1))]
        [(string=? k "-") (Img (Img-geo i) (Img-forma i) (Img-color i) (- (Img-tam i) 1))]
        [(string=? k "f1") (Img (Img-geo i) (Img-forma i) "red" (Img-tam i))]
        [(string=? k "f2") (Img (Img-geo i) (Img-forma i) "blue" (Img-tam i))]
        [(string=? k "f3") (Img (Img-geo i) (Img-forma i) "yellow" (Img-tam i))]
        [(string=? k "f4") (Img (Img-geo i) (Img-forma i) "green" (Img-tam i))]
        [(string=? k "f5") (Img (Img-geo i) (Img-forma i) "brown" (Img-tam i))]
        [(string=? k "f6") (Img (Img-geo i) (Img-forma i) "black" (Img-tam i))]
        [(string=? k " ") (Img ESCENA (Img-forma i) (Img-color i) (Img-tam i))]
        [else i]))

(define (mouse i x y evento)
  (cond [(string=? evento "button-down") (cond [(string=? (Img-forma i) "triangle") (Img (place-image (triangle (Img-tam i) "solid" (Img-color i))
                                                                                                 x y
                                                                                                 (Img-geo i))
                                                                                         (Img-forma i) (Img-color i) (Img-tam i))]
                                               [(string=? (Img-forma i) "square") (Img (place-image (square (Img-tam i) "solid" (Img-color i))
                                                                                                 x y
                                                                                                 (Img-geo i))
                                                                                       (Img-forma i) (Img-color i) (Img-tam i))]
                                               [(string=? (Img-forma i) "star") (Img (place-image (star (Img-tam i) "solid" (Img-color i))
                                                                                                 x y
                                                                                                 (Img-geo i))
                                                                                     (Img-forma i) (Img-color i) (Img-tam i))]
                                               [(string=? (Img-forma i) "circle") (Img (place-image (circle (Img-tam i) "solid" (Img-color i))
                                                                                                 x y
                                                                                                 (Img-geo i))
                                                                                       (Img-forma i) (Img-color i) (Img-tam i))])]
        [else i]))

(big-bang INICIAL
  [to-draw pantalla]
  [on-key teclado]
  [on-mouse mouse])