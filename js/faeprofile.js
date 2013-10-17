(function ($) {
  Drupal.behaviors.faeprofile = {
    attach: function(context, settings) {
			_staff_listing_staff_label();

			_staff_page_hide_empty_tab();
		}
	}

	function _staff_listing_staff_label() {
  	// Initial
  	$('<h4 class="staff_professional">Professional</h4>').insertBefore($('.grouped-staff-list .view-content table.views-table').last());

  	$('form#views-exposed-form-staff-page .form-item-field-person-type-tid input[type="radio"]').on('click', function(){
    	$(document).ajaxStop(function () {
      	$('h4.staff_professional').remove();
      	var tag_name = $('.grouped-staff-list .view-content table.views-table').last().prev().prop('tagName');
      	if(tag_name != 'H4') {
        	$('<h4 class="staff_professional">Professional</h4>').insertBefore($('.grouped-staff-list .view-content table.views-table').last());
      	}
    	});
  	});
	}

	function  _staff_page_hide_empty_tab() {
		var total_tab_num = $('[id^=quicktabs-tabpage-find_an_expert-]').length;
		var full_ids = [];
		
		var show_ids = [];
		var hide_ids = [];

		var tmp_objs = $('[id^=quicktabs-tabpage-find_an_expert-]').has('h3');
		tmp_objs.each(function(){
			 show_ids.push( $(this).prop('id').split('-').pop() );
		});

		for(var i=0; i<total_tab_num; i++) { 
			if(jQuery.inArray("" + i, show_ids) == -1) {
				hide_ids.push("" + i);	
			}
		}

		// Hide
		$.each(hide_ids, function(index, value){
			var div_id = 'quicktabs-tab-find_an_expert-' + value;
			$('#' + div_id).parent().hide();
		});

		// Show
		$.each(show_ids, function(index, value) {
			if(index == 0) {
				var div_id = 'quicktabs-tab-find_an_expert-' + value;
      	$('#' + div_id).parent().addClass('active');

				var div_id_1 = 'quicktabs-tabpage-find_an_expert-' + value;
				$('#' + div_id_1).removeClass('quicktabs-hide');
			}
		});
	}

})(jQuery);

