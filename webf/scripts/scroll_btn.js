let btn = $('#button');

$(window).scroll(async function () {
    if ($(window).scrollTop() > 300) {
        btn.show();
    } else {
        btn.hide();
    }
});


btn.on('click', async function(e) {
  e.preventDefault();
  $('html, body').animate({scrollTop:0}, '300');
});
