;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Diablo) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

(define P1 (circle 10 "solid" "blue"))
(define ESCENARIO (empty-scene 500 500 ))
(define INICIAL 250)

(define (pantalla x y)
  (place-image P1
               x y
               ESCENARIO))

(define (teclado x y k)
  (cond [else k]))

(big-bang INICIAL
  [to-draw pantalla]
  [on-key teclado])