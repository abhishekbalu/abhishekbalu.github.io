(function ($) {
    "use strict";

    /*------------------------------------------------------------------
    [Table of contents]

    0. CUSTOM PRE DEFINE FUNCTION
    1. pw GALLERY POPUP JS
    2. pw RESPONSIVE MENU
    3. pw MENU CLICK TO SCROLLDOWN
    4. pw GALLERY THREE COLUMN JS
    5. pw GALLERY TWO COLUMN JS

    -------------------------------------------------------------------*/

    /*--------------------------------------------------------------
    CUSTOM PRE DEFINE FUNCTION
    ------------------------------------------------------------*/
    /* is_exist() */
    jQuery.fn.is_exist = function () {
        return this.length;
    }


    $(function () {

        /*--------------------------------------------------------------
        pw GALLERY POPUP JS
        ------------------------------------------------------------*/
        var pw_img_popup = $('.pw_zoom_gallery.lightbox');
        if (pw_img_popup.is_exist()) {
            $(pw_img_popup).magnificPopup({
                type: 'image',
                closeOnContentClick: false,
                closeBtnInside: false,
                mainClass: 'mfp-with-zoom mfp-img-mobile',
                image: {
                    verticalFit: true,
                },
                gallery: {
                    enabled: true
                },
                zoom: {
                    enabled: true,
                    duration: 300, // don't foget to change the duration also in CSS
                    opener: function (element) {
                        return element.find('img');
                    }
                }
            });
        }

        /*--------------------------------------------------------------
        pw RESPONSIVE MENU
        ------------------------------------------------------------*/
        var header_menu = $('.pw_menu');
        if (header_menu.is_exist()) {
            header_menu.meanmenu({
                meanScreenWidth: "767",
                meanMenuContainer: '.pw-responsive-menu-panel',
            });
        }

        /*--------------------------------------------------------------
        pw MENU CLICK TO SCROLLDOWN
        ------------------------------------------------------------*/
        var $header_menu_link = $('.appmax-header-menu ul li a');
        if ($header_menu_link.is_exist()) {

            $header_menu_link.on("click", function (e) {
                var url = $(this).attr("href");
                var href = url.substring(url.indexOf('#') + 1),
                    href = '#' + href;
                if (/#/.test(this.href)) {
                    if ($(href).length) {
                        var offsetTop = href === "#" ? 0 : $(href).offset().top;
                        $('body , html').stop().animate({
                            scrollTop: offsetTop - 100,
                        }, 500);
                        e.preventDefault();
                        return false;
                    }
                }
            });
        }

    });


    $(window).on("load", function () {
        
        /*--------------------------------------------------------------
        pw GALLERY THREE COLUMN JS
        ------------------------------------------------------------*/
        var pw_filter_gallery = $('#pw_gallery_three_column');
        if (pw_filter_gallery.is_exist()) {
            var $container = $(pw_filter_gallery),
                colWidth = function () {
                    var w = $container.width(),
                        columnNum = 1,
                        columnWidth = 0;
                    if (w > 1200) {
                        columnNum = 3;
                    } else if (w > 900) {
                        columnNum = 3;
                    } else if (w > 600) {
                        columnNum = 2;
                    } else if (w > 450) {
                        columnNum = 2;
                    } else if (w > 385) {
                        columnNum = 1;
                    }
                    columnWidth = Math.floor(w / columnNum);
                    $container.find('.collection-grid-item').each(function () {
                        var $item = $(this),
                            multiplier_w = $item.attr('class').match(/collection-grid-item-w(\d)/),
                            multiplier_h = $item.attr('class').match(/collection-grid-item-h(\d)/),
                            width = multiplier_w ? columnWidth * multiplier_w[1] : columnWidth,
                            height = multiplier_h ? columnWidth * multiplier_h[1] * 0.4 - 12 : columnWidth * 0.5;
                        $item.css({
                            width: width,
                            //height: height
                        });
                    });
                    return columnWidth;
                },
                isotope = function () {
                    $container.isotope({
                        resizable: false,
                        itemSelector: '.collection-grid-item',
                        masonry: {
                            columnWidth: colWidth(),
                            gutterWidth: 0
                        }
                    });
                };
            isotope();
            $(window).on("resize", isotope);

            // filter items on button click
            $container.prev('.pw_gallery_menu').find('.watch-gallery-nav').on("click", 'a', function (e) {
                e.preventDefault();
                var filter_init = $(this).parent(),
                    filterValue = filter_init.attr('data-option-value');
                $container.isotope({
                    filter: filterValue
                });
                $(this).addClass('active').parent().siblings().find('a').removeClass('active');
                return false;
            });

        }

        /*--------------------------------------------------------------
        pw GALLERY TWO COLUMN JS
        ------------------------------------------------------------*/
        var pw_filter_gallery_2 = $('#pw_gallery_two_column');
        if (pw_filter_gallery_2.is_exist()) {
            var $container = $(pw_filter_gallery_2),
                colWidth = function () {
                    var w = $container.width(),
                        columnNum = 1,
                        columnWidth = 0;
                    if (w > 1200) {
                        columnNum = 2;
                    } else if (w > 900) {
                        columnNum = 2;
                    } else if (w > 600) {
                        columnNum = 2;
                    } else if (w > 450) {
                        columnNum = 2;
                    } else if (w > 385) {
                        columnNum = 1;
                    }
                    columnWidth = Math.floor(w / columnNum);
                    $container.find('.collection-grid-item').each(function () {
                        var $item = $(this),
                            multiplier_w = $item.attr('class').match(/collection-grid-item-w(\d)/),
                            multiplier_h = $item.attr('class').match(/collection-grid-item-h(\d)/),
                            width = multiplier_w ? columnWidth * multiplier_w[1] : columnWidth,
                            height = multiplier_h ? columnWidth * multiplier_h[1] * 0.4 - 12 : columnWidth * 0.5;
                        $item.css({
                            width: width,
                            //height: height
                        });
                    });
                    return columnWidth;
                },
                isotope = function () {
                    $container.isotope({
                        resizable: false,
                        itemSelector: '.collection-grid-item',
                        masonry: {
                            columnWidth: colWidth(),
                            gutterWidth: 0
                        }
                    });
                };
            isotope();
            $(window).on("resize", isotope);

            // filter items on button click
            $container.prev('.pw_gallery_menu').find('.watch-gallery-nav').on("click", 'a', function (e) {
                e.preventDefault();
                var filter_init = $(this).parent(),
                    filterValue = filter_init.attr('data-option-value');
                $container.isotope({
                    filter: filterValue
                });
                $(this).addClass('active').parent().siblings().find('a').removeClass('active');
                return false;
            });
        }
    });


})(jQuery);
