(function ($) {
  Drupal.behaviors.faeprofile = {
    attach: function(context, settings) {
			_hide_position_column();

			$('form[id^="views-exposed-form-staff-page"]').once('staff_listing_func', function(){
				_filter_by_subject_area();

			});
		}
	}


	function _filter_by_subject_area() {
		var checked_input_array;
		var study_area_on_page_array;
	
		// Which checkbox is checked.
		$('input[name^="field_person_area_tid"]').on("click", function() {
			checked_input_array = new Array();		
			$('input[name^="field_person_area_tid"]').each(function(index) {
				if($(this).prop('checked')) {
					checked_input_array.push( $(this).next().text() );
				}	
			});

			// Study areas on current page
			$(document).ajaxStop(function() {
				study_area_on_page_array = new Array();

				//console.log('time');

				$('h4.title').once().each(function(index) {
					study_area_on_page_array.push( $(this).text() );		
      	});

				if(checked_input_array.length > 0) {
					for(var i = 0; i < study_area_on_page_array.length; i = i + 1 ) {
    				var item = study_area_on_page_array[i];
						if(jQuery.inArray(item, checked_input_array) !== -1) {

							/*
							console.log('start-in-');
							console.log(item);
							console.log('end-in-');
							*/

							var mytext = "h4:contains('" + item + "')";
							$(mytext).show();
              $(mytext).next().show();
              $(mytext).next().next().show();
						}
						else {
					
							/*
							console.log('start-out-');
            	console.log(item);
            	console.log('end-out-');
					
							console.log('-start-');
        			console.log(checked_input_array);
        			console.log('----');
        			console.log(study_area_on_page_array);
        			console.log('-end-');
							*/	

							var mytext = "h4:contains('" + item + "')";
							$(mytext).hide();
							$(mytext).next().hide();
							$(mytext).next().next().hide();

							
						}
					}				
				}
			});

		});
	}

	function _hide_position_column() {
		$(document).ready(function() {
			$("th:contains('Position')").once().hide();
			$("td.staff-position").once().hide();

			// Display position for professional
			$("h4:contains('Professional')").next("table").find("th:contains('Position')").show();
			$("h4:contains('Professional')").next("table").find("td.staff-position").show();
		});
	}
 
})(jQuery);

