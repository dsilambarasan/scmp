<?php

function fetchData($url) {
	$username = 'admin';
  $password = 'admin';

  // Create a stream
  $opts = array(
    'http'=>array(
      'method'=>"GET",
      'header' => "Authorization: Basic " . base64_encode("$username:$password")
    )
  );
  $context = stream_context_create($opts);

  // Fetch data using the HTTP headers set above
  $feed = file_get_contents($url, false, $context);

  return $feed;
}

function fetchAllData() {
  $url = 'http://localhost:8080/export/article/1';
  return fetchData($url);
}

function fetchDataByDate($date = '') {
  if ($date != '') {
    $url = 'http://localhost:8080/day/article?date=' . $date;
    return fetchData($url);
  }
  else {
    return 'Date input is empty!';
  }
}

function fetchDataBetweenDates($fromDate, $toDate) {
  if ($fromDate != '' || $toDate != '') {
    $url = 'http://localhost:8080/export/articles?fromdate=' . $fromDate . '&toDate=' . $toDate;
    return fetchData($url);
  }
  else {
    return 'Provided date inputs are not valid!';
  }
}

function fetchDataByTopics($topic, $limit = 5) {
  if ($topic != '') {
    $url = 'http://localhost:8080/topic/articles?topic=' . $topic . '&limit=' . $limit;
    return fetchData($url);
  }
  else {
    return 'Please provide topic';
  }
}

// Get article by id.
print_r(fetchDataById(1));
#echo '<br>';

// Get articles for a day.
print_r(fetchDataByDate($day));
#echo '<br>';

// Get articles for a date range.
print_r(fetchDataBetweenDates($from, $to));
#echo '<br>';

// Get articles for a topic.
print_r(fetchDataByTopics('Weather'));

