;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica3 - 9|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;PROGRAMAS INTERACTIVOS
;Ej 9

(define SIZE 30)
(define CA (circle SIZE "solid" "blue"))
(define CV (circle SIZE "solid" "green"))
(define TA (triangle SIZE "solid" "blue"))
(define TV (triangle SIZE "solid" "green"))
(define FONDO (rectangle 200 200 "solid" "red"))

(define (pantalla f)
  (place-image f
               (random 200)
               (random 200)
               FONDO))

(define (teclado f k)
  (cond [(string=? "t" k) (cond [(image=? f CA) TA]
                                [(image=? f CV) TV]
                                [else f])]
        [(string=? "c" k) (cond [(image=? f TA) CA]
                                [(image=? f TV) CV]
                                [else f])]))

(define (cambio-color f)
  (cond [(image=? f CA) CV]
        [(image=? f CV) CA]
        [(image=? f TA) TV]
        [(image=? f TV) TA]
        [else f]))

(big-bang TV
  [to-draw pantalla]
  [on-tick cambio-color 1]
  [on-key teclado])