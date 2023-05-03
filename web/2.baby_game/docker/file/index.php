<!DOCTYPE html><html><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width,initial-scale=1,maximum-scale=1,user-scalable=no,minimal-ui"><title>Tower Building</title><link rel="icon" type="image/x-icon" href="./assets/favicon.png"><style>*{margin:0;padding:0}img{width:100%}html{background:#fff;height:100%}body{font-family:"Helvetica Neue",Arial,Helvetica,sans-serif;margin:0 auto;text-align:center;width:100%;height:100%;background:#f95240 url(assets/main-bg.png)}@media screen and (min-height:560px){html{font-size:100px}}@media screen and (min-height:640px){html{font-size:112.5px}}@media screen and (min-height:720px){html{font-size:125px}}@media screen and (min-height:800px){html{font-size:137.5px}}@media screen and (min-height:880px){html{font-size:150px}}@media screen and (min-height:960px){html{font-size:162.5px}}@media screen and (min-height:1040px){html{font-size:180px}}@media screen and (min-height:1200px){html{font-size:200px}}html{font-size:17.6vh}#canvas{position:fixed;left:0;top:0;right:0;bottom:0;margin:auto}a{text-decoration:none}li,ol,ul{list-style-type:none;padding:0;margin:0}.hide{display:none}.clear{clear:both}.loading{background-color:#f05a50;height:100%;width:100%}.loading .main{width:60%;margin:0 auto;color:#fff}.loading .main img{width:60%;margin:1rem auto 0}.loading .main .title{font-size:.3rem}.loading .main .text{font-size:.15rem}.loading .main .bar{height:.12rem;width:100%;border:3px solid #fff;border-radius:.6rem;margin:.1rem 0}.loading .main .bar .sub{height:.1rem;width:98%;margin:.008rem auto 0}.loading .main .bar .percent{height:100%;width:0;background-color:#fff;border-radius:.6rem}.loading .logo{position:absolute;bottom:.3rem;left:0;right:0}.loading .logo img{width:1rem}.content{height:100vh;margin:0 auto;position:relative}.landing .title{width:60%}.landing .logo{width:30%;position:absolute;right:.2rem;top:.2rem}.landing .action-2{position:absolute;bottom:.2rem;width:100%}.landing .start{width:65%}.slideTop{-webkit-animation:st 1s ease-in-out;animation:st 1s ease-in-out}@-webkit-keyframes st{0%{transform:translateZ(0)}100%{transform:translate3d(0,-100%,0)}}@keyframes st{0%{transform:translateZ(0)}100%{transform:translate3d(0,-100%,0)}}.slideBottom{-webkit-animation:sb 1s ease-in-out;animation:sb 1s ease-in-out}@-webkit-keyframes sb{0%{transform:translateZ(0)}100%{transform:translate3d(0,200%,0)}}@keyframes sb{0%{transform:translateZ(0)}100%{transform:translate3d(0,200%,0)}}.swing{-webkit-animation:sw 2s ease-in-out alternate infinite;animation:sw 2s ease-in-out alternate infinite}@-webkit-keyframes sw{0%{transform:rotate(5deg);transform-origin:top center}100%{transform:rotate(-5deg);transform-origin:top center}}@keyframes sw{0%{transform:rotate(5deg);transform-origin:top center}100%{transform:rotate(-5deg);transform-origin:top center}}.modal .mask{background-color:#000;opacity:.6;position:fixed;height:100%;width:100%;top:0;left:0}.modal .modal-content{position:fixed;height:100%;width:90%;margin-top:.3rem;top:0}.modal .main{width:85%;margin:0 auto}.modal .container{position:relative}.modal .bg{width:100%;position:absolute;top:0;left:0}.modal .modal-main{width:100%;position:absolute;top:0;left:0;margin-top:-.4rem}.modal .over-img{width:80%;margin:.8rem auto 0}.modal .over-score{margin-top:-.2rem;font-size:.5rem;color:#ff735c;text-shadow:-2px -2px 0 #fff,2px -2px 0 #fff,-2px 2px 0 #fff,2px 2px 0 #fff}.modal .tip{font-size:.16rem;color:#9b724e}.modal .over-button-b{width:70%;margin:.1rem auto 0}.wxShare{background:#000;position:absolute;top:0;left:0;width:100%;height:100%;z-index:11;opacity:.9}.wxShare img{width:50%;float:right;margin:10px 10px 0 0}@font-face{font-family:wenxue;src:url(assets/wenxue.eot);src:url(assets/wenxue.eot),url(assets/wenxue.woff),url(assets/wenxue.ttf),url(assets/wenxue.svg)}.font-wenxue{font-family:wenxue}</style></head><body><canvas id="canvas" class="hide"></canvas><div class="content"><div class="loading"><div class="main"><img src="./assets/main-loading.gif"><div class="progress"><div class="title font-wenxue">0%</div><div class="bar"><div class="sub"><div class="percent"></div></div></div><div class="text">Loading...</div></div></div></div><div class="landing hide"><div class="action-1"><img src="./assets/main-index-title.png" class="title swing"></div><div class="action-2"><img id="start" src="./assets/main-index-start.png" class="start"></div></div><div id="modal" class="modal hide"><div class="mask"></div><div class="js-modal-content modal-content"><div class="main"><div class="container"><img src="./assets/main-modal-bg.png" class="bg"><div class="modal-main"><div id="over-modal" class="hide js-modal-card"><img src="./assets/main-modal-over.png" class="over-img"><div id="score" class="over-score font-wenxue"></div><div id="over-zero" class="hide"><div class="tip"><p>Try Again!</p><img src="./assets/main-modal-again-b.png" class="over-button-b js-reload"><img src="./assets/main-modal-invite-b.png" class="over-button-b js-invite"></div></div></div></div></div></div></div></div><div class="wxShare hide"><img src="./assets/main-share-icon.png"></div></div><script src="./dist/main.js"></script><script src="./assets/zepto-1.1.6.min.js"></script><script>var domReady, loadFinish, canvasReady, loadError, gameStart, game, score, successCount
  // init window height and width
  var gameWidth = window.innerWidth
  var gameHeight = window.innerHeight
  var ratio = 1.5
  if (gameHeight / gameWidth < ratio) {
    gameWidth = Math.ceil(gameHeight / ratio)
  }
  $('.content').css({ "height": gameHeight + "px", "width": gameWidth + "px" })
  $('.js-modal-content').css({ "width": gameWidth + "px" })

  // loading animation
  function hideLoading() {
    if (domReady && canvasReady) {
      $('#canvas').show()
      loadFinish = true
      setTimeout(function () {
        $('.loading').hide()
        $('.landing').show()
      }, 1000)
    }
  }

  function updateLoading(status) {
    var success = status.success
    var total = status.total
    var failed = status.failed
    if (failed > 0 && !loadError) {
      loadError = true
      alert('Network error... Please try again.')
      return
    }
    var percent = parseInt((success / total) * 100);
    if (percent === 100 && !canvasReady) {
      canvasReady = true
      hideLoading()
    }
    percent = percent > 98 ? 98 : percent
    percent = percent + '%'
    $('.loading .title').text(percent);
    $('.loading .percent').css({
      'width': percent
    })
  }

  function overShowOver() {
    $('#modal').show()
    $('#over-modal').show()
    $('#over-zero').show()
  }

  // game customization options
  const option = {
    width: gameWidth,
    height: gameHeight,
    canvasId: 'canvas',
    soundOn: true,
    setGameScore: function (s) {
      score = s
    },
    setGameSuccess: function (s) {
      successCount = s
    },
    setGameFailed: function (f) {
      $('#score').text(score)
      if (f >= 3) overShowOver()
    }
  }

  // game init with option
  function gameReady() {
    game = TowerGame(option)
    game.load(function () {
      game.init()
      setTimeout(function () {
        game.playBgm()
      })
    }, updateLoading)
  }

  var isWechat = navigator.userAgent.toLowerCase().indexOf("micromessenger") !== -1
  if (isWechat) {
    document.addEventListener("WeixinJSBridgeReady", gameReady, false)
  } else {
    gameReady()
  }

  function indexHide() {
    $('.landing .action-1').addClass('slideTop')
    $('.landing .action-2').addClass('slideBottom')
    setTimeout(function () {
      $('.landing').hide()
    }, 950)
  }

  // click event
  $('#start').on('click', function () {
    if (gameStart) return
    gameStart = true
    setTimeout(function () {
      game.playBgm()
    })
    indexHide()
    setTimeout(game.start, 400)
  })

  $('.js-reload').on('click', function () {
    window.location.href = window.location.href + '?s=' + (+new Date())
  })

  $('.js-invite').on('click', function () {
    $('.wxShare').show()
  })

  $('.wxShare').on('click', function () {
    $('.wxShare').hide()
  })

  // listener
  window.addEventListener('load', function () {
    domReady = true
    hideLoading()
  }, false);</script><script async src="https://www.googletagmanager.com/gtag/js?id=G-YCWZ8ZDCH2"></script><script>function gtag(){dataLayer.push(arguments)}window.dataLayer=window.dataLayer||[],gtag("js",new Date),gtag("config","G-YCWZ8ZDCH2")</script></body></html>