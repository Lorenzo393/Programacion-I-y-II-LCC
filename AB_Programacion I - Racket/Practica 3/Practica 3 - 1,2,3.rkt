;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname |Practica3 - 1,2,3|) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
(require 2htdp/universe)
(require racket/base)
(require test-engine/racket-tests)

;PROGRAMAS INTERACTIVOS
;Ej 1, 2 y 3
(define INICIAL 100)

(define (pantalla r)
  (cond [(and (>= r 0) (<= r 50)) (place-image (circle r "solid" "yellow")
               150
               150
               (empty-scene 300 300))]
        [(and (> r 50) (<= r 100)) (place-image (circle r "solid" "red")
               150
               150
               (empty-scene 300 300))]
        [(> r 100) (place-image (circle r "solid" "blue")
               150
               150
               (empty-scene 300 300))]))

(define (disminuir r)
  (cond [(= r 0) r]
        [else (- r 10)]))

(define (incrementar r)
  (cond [(>= r 150) 0]
        [else (+ r 1)]))

(define (teclado r k)
  (cond [(string=? k "d") (* 10 r)]
        [else r]))

(define (terminar? r)
  (if (>= r 150) #t #f))

(big-bang INICIAL
  [to-draw pantalla]
  [on-tick incrementar 0.02]
  [on-key teclado]
  [stop-when terminar?])