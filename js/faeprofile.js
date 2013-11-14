(function ($) {
  Drupal.behaviors.faeprofile = {
    attach: function(context, settings) {
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
						}
						else {
					
							/*
							console.log('start-out-');
            	console.log(item);
            	console.log('end-out-');
							*/
						
							var mytext = "h4:contains('" + item + "')";
							$(mytext).hide();
							$(mytext).next().hide();
							$(mytext).next().next().hide();
						}
					}				
				}

				/*
				console.log('-start-');
				console.log(checked_input_array);
    	  console.log('----');
    	  console.log(study_area_on_page_array);
				console.log('-end-');
				*/
			});


		});
	}	
})(jQuery);

