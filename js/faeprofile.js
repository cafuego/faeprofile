(function ($) {
  Drupal.behaviors.faeprofile = {
    attach: function(context, settings) {
			_staff_listing_staff_label();
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
})(jQuery);

