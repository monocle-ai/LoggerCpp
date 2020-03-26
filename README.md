# SwiFTLog

[![Project Status: WIP – Initial development is in progress, but there has not yet been a stable, usable release suitable for the public.](https://www.repostatus.org/badges/latest/wip.svg)](https://www.repostatus.org/#wip) [![Lang](https://badgen.net/lgtm/langs/g/sayantanroy47/LoggerCpp/cpp?color=green)](https://abc.com) [![Documentation](https://codedocs.xyz/sayantanroy47/LoggerCpp.svg)](https://codedocs.xyz/sayantanroy47/LoggerCpp/) [![Reviewed by Hound](https://img.shields.io/badge/Reviewed_by-Hound-8E64B0.svg)](https://houndci.com) [![Hits-of-Code](https://hitsofcode.com/github/sayantanroy47/LoggerCpp)](https://hitsofcode.com/view/github/sayantanroy47/LoggerCpp)

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/5a753190bbca44dcb8d3d2a903fb34eb)](https://app.codacy.com/manual/sayantanroy47/LoggerCpp?utm_source=github.com&utm_medium=referral&utm_content=sayantanroy47/LoggerCpp&utm_campaign=Badge_Grade_Dashboard)
[![CodeFactor](https://www.codefactor.io/repository/github/sayantanroy47/loggercpp/badge)](https://www.codefactor.io/repository/github/sayantanroy47/loggercpp)
[![CodeInspector](https://www.code-inspector.com/project/5296/score/svg)](https://frontend.code-inspector.com/public/project/5296/LoggerCpp/dashboard)
[![CodeInspector](https://www.code-inspector.com/project/5296/status/svg)](https://frontend.code-inspector.com/project/5296/dashboard)
---

---
Build Status
---
<b>
<table>
    <tr>
        <td>
            master
        </td>
        <td>
           <a href="https://travis-ci.com/sayantanroy47/LoggerCpp/"><img src="https://travis-ci.com/sayantanroy47/LoggerCpp.svg?branch=master"></a>
        </td>
        <td>
             <a href="https://ci.appveyor.com/project/sayantanroy47/loggercpp/branch/master"><img src="https://ci.appveyor.com/api/projects/status/s0yie9ahhsj2m2hj/branch/master?svg=true"></a>
        </td>
        <td>
            <a href="https://github.com/sayantanroy47/LoggerCpp/actions?query=workflow%3Abuild%28M%29"><img src="https://github.com/sayantanroy47/LoggerCpp/workflows/build(M)/badge.svg?branch=master"></a>
        </td>
         <td>
            <a href="https://app.circleci.com/pipelines/github/sayantanroy47/LoggerCpp?branch=master"><img src="https://img.shields.io/circleci/build/gh/sayantanroy47/LoggerCpp/master?logo=circleci&style=plastic"></a>
        </td>
        <td>
            <a href="https://g.codefresh.io/pipelines/CodeFresh%20Pipe/builds?repoOwner=sayantanroy47&repoName=LoggerCpp&serviceName=sayantanroy47%252FLoggerCpp&filter=trigger:build~Build;branch:master;pipeline%3A5e774d070c0a28272084c618~CodeFresh%20Pipe">
	<img alt="Codefresh build status" src="https://g.codefresh.io/api/badges/pipeline/sayantan/SwiFTLog%2FCodeFresh%20Pipe?branch=master&key=eyJhbGciOiJIUzI1NiJ9.NWU3NzQwYWM4YWI3NWQzNGVlYjkxZjkw.QMynCSIXB7J72wsAjzC8Gm_iG9He725UIUAdgfTSWqw&type=cf-1">
</a>
        </td>
    </tr>
    <tr>
        <td>
            development
        </td>
        <td> <a href="https://travis-ci.com/sayantanroy47/LoggerCpp/"><img src="https://travis-ci.com/sayantanroy47/LoggerCpp.svg?branch=development"></a>
        </td>
        <td>
             <a href="https://ci.appveyor.com/project/sayantanroy47/loggercpp/branch/development"><img src="https://ci.appveyor.com/api/projects/status/s0yie9ahhsj2m2hj/branch/development?svg=true"></a>
        </td>
        <td>
            <a href="https://github.com/sayantanroy47/LoggerCpp/actions?query=workflow%3Abuild%28D%29"><img src="https://github.com/sayantanroy47/LoggerCpp/workflows/build(D)/badge.svg?branch=development"></a>
        </td>
        <td>
            <a href="https://app.circleci.com/pipelines/github/sayantanroy47/LoggerCpp?branch=development"><img src="https://img.shields.io/circleci/build/gh/sayantanroy47/LoggerCpp/development?logo=circleci&style=plastic"></a>
        </td>
        <td>
           <a href="https://g.codefresh.io/pipelines/CodeFresh%20Pipe/builds?repoOwner=sayantanroy47&repoName=LoggerCpp&serviceName=sayantanroy47%252FLoggerCpp&filter=trigger:build~Build;branch:development;pipeline%3A5e774d070c0a28272084c618~CodeFresh%20Pipe">
	<img alt="Codefresh build status" src="https://g.codefresh.io/api/badges/pipeline/sayantan/SwiFTLog%2FCodeFresh%20Pipe?branch=development&key=eyJhbGciOiJIUzI1NiJ9.NWU3NzQwYWM4YWI3NWQzNGVlYjkxZjkw.QMynCSIXB7J72wsAjzC8Gm_iG9He725UIUAdgfTSWqw&type=cf-1">
</a>
        </td>
    </tr>
</table>

---
Build History
---
**Appveyor** &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  **Travis** &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;  &nbsp;**CircleCI**

[![Build history](https://buildstats.info/appveyor/chart/sayantanroy47/LoggerCpp)](https://ci.appveyor.com/project/sayantanroy47/LoggerCpp/history)
[![Build history](https://buildstats.info/travisci/chart/sayantanroy47/LoggerCpp?showStats=true)](https://travis-ci.com/github/sayantanroy47/LoggerCpp/builds)
[![Build history](https://buildstats.info/circleci/chart/sayantanroy47/LoggerCpp?showStats=true)](https://app.circleci.com/pipelines/github/sayantanroy47/LoggerCpp/mine)


Central Logging in C++
